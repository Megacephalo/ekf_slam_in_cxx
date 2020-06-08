#include "odometry_motion_model.h"

Odometry_Motion_Model::Odometry_Motion_Model(int landmark_nums, int rob_pose_dim, float motion_noise) 
: landmark_nums_(landmark_nums)
, rob_pose_dim_(rob_pose_dim)
, motion_noise_(motion_noise)
{
	state_ = Eigen::VectorXd::Zero(rob_pose_dim + 2 * landmark_nums_, 1) ; // vector of dim (3 * 2N) x 1
	robCov_ = Eigen::MatrixXd::Zero(rob_pose_dim_, rob_pose_dim_) ;
	robMapCov_ = Eigen::MatrixXd::Zero(rob_pose_dim_, 2 * landmark_nums_) ;
	mapCov_ = INF * Eigen::MatrixXd::Identity(2 * landmark_nums_, 2 * landmark_nums_) ;

	// The dimension of Covariance is (3 * 2N x 3 * 2N)
	Covariance_ = Eigen::MatrixXd::Zero(rob_pose_dim_ + 2 * landmark_nums_, rob_pose_dim_ + 2 * landmark_nums_) ;
	Covariance_.topLeftCorner(rob_pose_dim_, rob_pose_dim_) = robCov_ ;
	Covariance_.topRightCorner(rob_pose_dim_, 2 * landmark_nums_) ;
	Covariance_.bottomLeftCorner(2 * landmark_nums_, rob_pose_dim_) = robMapCov_.transpose() ;
	Covariance_.bottomRightCorner(2 * landmark_nums_, 2 * landmark_nums_) = mapCov_ ;

	gauss_noise_ = Eigen::MatrixXd::Zero(rob_pose_dim_ + 2 * landmark_nums_, rob_pose_dim_ + 2 * landmark_nums_) ;
	gauss_noise_.topLeftCorner(3, 3) << motion_noise_	,	0				,	0					,
												0		,	motion_noise_	,	0					,
												0		,	0				,	motion_noise_/ 10 	;
} /* End of default constructor */

void
Odometry_Motion_Model::setState(const Eigen::VectorXd& state) {
	state_ = state ;
} /* End of setState */

void
Odometry_Motion_Model::setState(const Eigen::VectorXd& prev_state, const double r1, const double& t, const double& r2) {
	double angle = state_(2) ;  // NOTE! The angle unit is radian instead of degree !!
	float c = std::cos(angle + r1) ;
	float s = std::sin(angle + r1) ;

	state_(0) = prev_state(0) + t * c ;
	state_(1) = prev_state(1) + t * s ;
	state_(2) = prev_state(2)+ r1 + r2 ;
} /* End of setState */

Eigen::VectorXd
Odometry_Motion_Model::getState() const {
	return state_ ;
} /* End of getState */

Eigen::MatrixXd
Odometry_Motion_Model::getCovariance() const {
	return Covariance_ ;
} /* End of getCovariance */

void
Odometry_Motion_Model::setCovariance(const Eigen::MatrixXd& sigma) {
	Covariance_ = sigma ;
} /* End of setCovariance */

Eigen::MatrixXd
Odometry_Motion_Model::getMotionNoise() const {
	return gauss_noise_ ;
} /* End of getMotionNoise */