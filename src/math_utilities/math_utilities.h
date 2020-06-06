#ifndef _MATH_UTILITIES_H_
#define _MATH_UTILITIES_H_

#include <Eigen/Dense>

class Math_utilities {
  public:
  	void normalize_bearing(Eigen::VectorXd& Z) ; //<! Normalize phi to be between -pi and pi
  	float normalize_angle(float phi) ;
} ; /* End of class */

#endif /* _MATH_UTILITIES_H_ */