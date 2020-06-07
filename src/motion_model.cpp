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

std::ostream&
operator << (std::ostream& os, const std::unique_ptr<Motion_model>& motion) {
	os << "Motion r1: " << std::left << std::setw(10) << motion->r1() << "t: " << std::left << std::setw(10) << motion->t()  << "r2: " << std::left << std::setw(10) << motion->r2() ;
	return os ;
} /* End of operator overloading */

std::ostream&
operator << (std::ostream& os, const std::shared_ptr<Motion_model>& motion) {
	os << "Motion r1: " << std::left << std::setw(10) << motion->r1() << "t: " << std::left << std::setw(10) << motion->t()  << "r2: " << std::left << std::setw(10) << motion->r2() ;
	return os ;
}