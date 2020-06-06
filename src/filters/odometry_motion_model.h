#ifndef _ODOMETRY_MOTION_MODEL_H_
#define _ODOMETRY_MOTION_MODEL_H_

#include <Eigen/Dense>
#include <vector>
#include <cmath>

#include <limits>
#define INF std::numeric_limits<double>::max()

class Odometry_Motion_Model {
  public:
  	Odometry_Motion_Model(int landmark_nums, int rob_pose_dim, float motion_noise = 0.1) ;
  	void setState(const Eigen::VectorXd& state) ;
  	void setState(const double r1, const double& t, const double& r2) ;
  	Eigen::VectorXd getState() const ;
  	Eigen::MatrixXd getCovariance() const ;
  	void setCovariance(const Eigen::MatrixXd& sigma) ;
  private:
  	int landmark_nums_ ;
  	int rob_pose_dim_ ;
  	Eigen::VectorXd state_ ;
  	// ------ these are used to define the dimensions of sub-matrices --------
  	Eigen::MatrixXd robMapCov_ ;
  	Eigen::MatrixXd robCov_ ;
  	Eigen::MatrixXd mapCov_ ;
  	// ------ these are used to define the dimensions of sub-matrices --------
  	Eigen::MatrixXd Covariance_ ;
  	float motion_noise_ ;
  	Eigen::MatrixXd gauss_noise_ ;
} ; /* End of class */

#endif /* _ODOMETRY_MOTION_MODEL_H_ */