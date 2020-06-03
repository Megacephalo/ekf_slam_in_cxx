#include "motion_model.h"

Motion_model::Motion_model(const float& r1, const float& t, const float& r2) 
: r1_(r1)
, t_(t)
, r2_(r2)
{} /* End of copy constructor */

Motion_model::~Motion_model()
{} /* End of destructor */

float
Motion_model::r1() {
	return r1_ ;
} /* End of r1 */

float
Motion_model::t() {
	return t_ ;
} /* End of r1 */

float
Motion_model::r2() {
	return r2_ ;
} /* End of r1 */
