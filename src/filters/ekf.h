#ifndef _EKF_H_
#define _EKF_H_

#include <vector>
#include <memory>
#include <cmath>

#include "math_utilities.h"
#include "filter_base.h"
#include "odometry_motion_model.h"


class EKF : public Filter_base {
  public:
  	void initialize(const LandmarkSet& map, const int& rob_pose_dim = 3) ;
  	void execute(const Sensor_Records& state) ;
  	Eigen::VectorXd getMean() const ;
  	Eigen::MatrixXd getCovariance() const ;
  	std::vector<bool> get_observed_landmarks() const ;
  private:
  	std::unique_ptr<Odometry_Motion_Model> wheel_odom_ ;
  	std::vector<bool> are_observed_landmarks_ ;
  	Eigen::VectorXd mean_ ;
  	Eigen::MatrixXd covariance_ ;
  	Math_utilities math_ ;

  	void predict(const std::shared_ptr<Motion_model>& motion) ;
  	void update(const observations& observations) ;

} ; /* End of class */

#endif /* _EKF_H_ */