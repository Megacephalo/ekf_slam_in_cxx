#ifndef _MOTION_MODEL_H_
#define _MOTION_MODEL_H_

#include <iostream>
#include <iomanip>
#include <memory>

struct Motion_model {
	Motion_model(const float& r1, const float& t, const float& r2) ;
	virtual ~Motion_model() ;

	virtual float r1() ;
	virtual float t() ;
	virtual float r2() ;

  protected:
	float r1_ ;
	float t_ ;
	float r2_ ;
} ; /* End of class */

std::ostream& operator << (std::ostream& os, const std::unique_ptr<Motion_model>& motion) ;
std::ostream& operator << (std::ostream& os, const std::shared_ptr<Motion_model>& motion) ;

#endif /* _MOTION_MODEL_H_ */