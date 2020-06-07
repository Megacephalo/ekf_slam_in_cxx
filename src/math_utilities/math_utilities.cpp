#include "math_utilities.h"

void
Math_utilities::normalize_bearing(Eigen::VectorXd& Z) {
	for (int i = 1; i < Z.size() ; i += 2) {
		Z(i) = normalize_angle( Z(i) ) ;
	}
} /* End of normalize_bearing */

float
Math_utilities::normalize_angle(float phi) {
	phi = fmod(phi + M_PI, 2 * M_PI) ;
	if (phi < 0) {
		phi += 2 * M_PI ;
	}
	return phi ;
} /* End of normalize_angle */

float
Math_utilities::normalize_angle_to_2pi(float phi) {
	phi = fmod( phi, 2 * M_PI ) ;
	if (phi < 0) {
		phi += 2 * M_PI ;
	}
	return phi ;
}

float
Math_utilities::deg2rad(float deg) {
	return ( deg * M_PI / 180. ) ;
} /* End of deg2rad */

float
Math_utilities::rad2deg(float rad) {
	return ( rad * 180. / M_PI ) ;
} /* End of rad2deg */