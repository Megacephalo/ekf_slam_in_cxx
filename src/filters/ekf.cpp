#include "ekf.h"

void
EKF::initialize(const LandmarkSet& map, const int& rob_pose_dim) {
	wheel_odom_ = std::unique_ptr<Odometry_Motion_Model>( new Odometry_Motion_Model(map.size(), rob_pose_dim) ) ;
	are_observed_landmarks_.resize(map.size()) ;
	std::fill(are_observed_landmarks_.begin(), are_observed_landmarks_.end(), false) ;

	mean_ = wheel_odom_->getState() ;
	covariance_ = wheel_odom_->getCovariance() ;
} /* End of initialize */

void
EKF::execute(const Sensor_Records& state) {
	control u = state.getState().first ;
	observations z = state.getState().second ;

	this->predict(u) ;
	this->update(z) ;
} /* End of execute */

Eigen::VectorXd
EKF::getMean() const {
	return mean_ ;
} /* End of getMean */

Eigen::MatrixXd
EKF::getCovariance() const {
	return covariance_ ;
} /* End of getCovariance */

std::vector<bool>
EKF::get_observed_landmarks() const {
	return are_observed_landmarks_ ;
} /* End of get_observed_landmarks */

void
EKF::predict(const std::shared_ptr<Motion_model>& motion) {
	double prev_angle = mean_(2) ;
	double r1 = motion->r1() ;
	double t = motion->t() ;
	double r2 = motion->r2() ;
	Eigen::MatrixXd motionJacobian = Eigen::MatrixXd(3, 3) ;
	motionJacobian << 	1	,	0	,	-t * std::sin(prev_angle + r1)	,
						0	,	1	,	t * std::cos(prev_angle + r1)	,
						0	,	0	,	0 							;

	// wheel_odom_->setState(mean_, r1, t, r2) ;
	// mean_ = wheel_odom_->getState() ;
	mean_(0) += t * std::cos(prev_angle + r1) ;
	mean_(1) += t * std::sin(prev_angle + r1) ;
	mean_(2) += r1 + r2 ;

	int cov_dim = covariance_.cols() ;
	covariance_.topLeftCorner(3, 3) = motionJacobian * covariance_.topLeftCorner(3, 3) * motionJacobian.transpose() ;
	covariance_.topRightCorner(3, cov_dim - 3) = motionJacobian * covariance_.topRightCorner(3, cov_dim - 3) ;
	covariance_.bottomLeftCorner(cov_dim - 3, 3) = covariance_.topRightCorner(3, cov_dim - 3).transpose() ;
	covariance_ += wheel_odom_->getMotionNoise() ;
} /* End of predict */

void
EKF::update(const observations& observations) {
	/* Range bearing observation */
	int measure_num = observations.size() ;

	// z = <range_i, bearing_i>T
	Eigen::VectorXd Z = Eigen::VectorXd::Zero(2 * measure_num) ;
	Eigen::VectorXd expectedZ = Eigen::VectorXd::Zero(2 * measure_num) ;

	// H: the observation Jacobian
	int landmarks_num = are_observed_landmarks_.size() ;
	Eigen::MatrixXd obsJacobian = Eigen::MatrixXd::Zero(2 * measure_num, 3 + 2 * landmarks_num) ;
	
	// for all observed features
	for (int i = 0 ; i < measure_num ; i++) {
		std::shared_ptr<Observation_model> reading = observations.at(i) ;
		long long landmarkId = reading->id() ;
		float range = reading->range() ;
		float bearing = reading->bearing() ;

		// if landmark is not seen before, initialize it
		if ( !are_observed_landmarks_.at(landmarkId - 1) ) {
			float prev_angle = mean_(2) ;
			mean_(2 * landmarkId + 1) = mean_(0) + range * std::cos( prev_angle + bearing ) ;
			mean_(2 * landmarkId + 2) = mean_(1) + range * std::sin( prev_angle + bearing ) ;
			// mark this feature as an observed landmark
			are_observed_landmarks_.at(landmarkId - 1) = true ;
		}

		// add the landmark to the Z vector
		Z(2 * i) = range ;
		Z(2 * i + 1) = bearing ;
		// use the current estimate of the landmark pose
		double delta_x = mean_(2 * landmarkId + 1) - mean_(0) ;
		double delta_y = mean_(2 * landmarkId + 2) - mean_(1) ;
		// q = delta ^T * delta
		double q = std::pow(delta_x, 2) + std::pow(delta_y, 2) ;
		// z^i_t = [sqrt(q)  atan2*(delta_y, delta_x) - est_mu_(t, theta) est_mu_(j, s)]^T
		// not sure why est_mu_(j, s) is not included
		expectedZ(2 * i) = std::sqrt(q) ;
		expectedZ(2 * i + 1) = std::atan2(delta_y, delta_x) - mean_(2) ;

		obsJacobian.block<2, 3>(2 * i, 0) << -std::sqrt(q) * delta_x / q	,	-std::sqrt(q) * delta_y / q	,	0	,
												delta_y / q					,	-delta_x / q				,	-1	;

		obsJacobian.block<2, 2>(2 * i, 2 * landmarkId + 1) << std::sqrt(q) * delta_x / q	,	std::sqrt(q) * delta_y / q	,
																-delta_y / q				, 	delta_x / q					;
		// where is F_(x, j) ?
	}

	float perception_noise = 0.01 ;
	// Q: the sensor noise matrix
	Eigen::MatrixXd sensor_noise = Eigen::MatrixXd::Identity(2 * measure_num, 2 * measure_num) * perception_noise ;

	// compute Kalman gain
	Eigen::MatrixXd Ht = obsJacobian.transpose() ;
	Eigen::MatrixXd HQ = ( obsJacobian * covariance_ * Ht ) + sensor_noise ;
	Eigen::MatrixXd Si = HQ.inverse() ;
	Eigen::MatrixXd KalmanGain = covariance_ * Ht * Si ;

	Eigen::VectorXd diff = Z - expectedZ ;
	math_.normalize_bearing(diff) ;
	mean_ += KalmanGain * diff ;
	mean_(2) = math_.normalize_angle( mean_(2) ) ;
	covariance_ = covariance_ - KalmanGain * obsJacobian * covariance_ ;
} /* End of update */

