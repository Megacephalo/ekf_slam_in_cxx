#ifndef _OBSERVATION_MODEL_H_
#define _OBSERVATION_MODEL_H_

#include <iostream>
#include <iomanip>
#include <memory>
#include <Eigen/Dense>

struct Observation_model {
  	Observation_model(const long long& id = 0, const float& range = 0., const float& bearing = 0.) ;
	virtual ~Observation_model() ;

	virtual long long id() ;
	virtual float range() ;
	virtual float bearing() ;

	

  protected:
	long long id_ ;
	float range_ ;
	float bearing_ ;
} ; /* End of struct */

std::ostream& operator << (std::ostream& os, const std::shared_ptr<Observation_model>& obs) ;
std::ostream& operator << (std::ostream& os, const std::unique_ptr<Observation_model>& obs) ;
#endif /* _OBSERVATION_MODEL_H_ */