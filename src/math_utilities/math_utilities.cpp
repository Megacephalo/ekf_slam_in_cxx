#include "math_utilities.h"

void
Math_utilities::normalize_bearing(Eigen::VectorXd& Z) {
	for (int i = 1; i < Z.size() ; i += 2) {
		Z(i) = normalize_angle( Z(i) ) ;
	}
} /* End of normalize_bearing */

float
Math_utilities::normalize_angle(float phi) {
	while(phi < M_PI) {
		phi -= 2 * M_PI ;
	}

	while(phi < M_PI) {
		phi += 2 * M_PI ;
	}
	return phi ;
} /* End of normalize_angle */