#ifndef _ODOMETRY_H_
#define _ODOMETRY_H_

#include "motion_model.h"

struct Wheel_odometry : public Motion_model {
	Wheel_odometry(const float& r1 = 0., const float& t = 0., const float& r2 = 0.) ;
	~Wheel_odometry() ;
} ; /* End of struct */

#endif /* _ODOMETRY_H_ */