#ifndef _MATH_UTILITIES_H_
#define _MATH_UTILITIES_H_

#include <Eigen/Dense>
#include <cmath>

class Math_utilities {
  public:
  	void normalize_bearing(Eigen::VectorXd& Z) ; 
  	float normalize_angle(float phi) ; //<! Normalize phi to be between -pi and pi
  	float normalize_angle_to_2pi(float phi) ; //<! Normalize phi to be between 0 and 2 * pi
  	float deg2rad(float deg) ;
  	float rad2deg(float rad) ; 
} ; /* End of class */

#endif /* _MATH_UTILITIES_H_ */