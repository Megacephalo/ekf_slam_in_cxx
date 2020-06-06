#ifndef _FILTER_BASE_H_
#define _FILTER_BASE_H_

#include <Eigen/Dense>

#include "sensor_records.h"
#include "map_point.h"
#include "motion_model.h"
#include "observation_model.h"

/**
This class serves as an interface to which all actual definitions of
Bayesian filters inherit from. The derived filters include parametric ones
such as Extended Kalman Filter (EKF), Unscented Kalman Filter (UKF); whereas
the non-parametric filters such as Particle filter version 1.0 or 2.0 
**/

class Filter_base {
  public:
  	Filter_base() {} /* End of default constructor */
  	virtual ~Filter_base() {} /* End of destructor */
  	virtual void initialize(const LandmarkSet& map, const int& rob_pose_dim) = 0 ;
  	virtual void execute(const Sensor_Records& state) = 0 ;
  	virtual Eigen::VectorXd getMean() const = 0 ;
  	virtual Eigen::MatrixXd getCovariance() const = 0 ;
  	virtual std::vector<bool> get_observed_landmarks() const = 0 ;
} ; /* End of class */

#endif /* _FILTER_BASE_H_ */