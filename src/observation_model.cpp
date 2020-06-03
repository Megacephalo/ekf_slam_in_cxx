#include "observation_model.h"

Observation_model::Observation_model( const long long& id
									, const float& range
									, const float& bearing)
: id_(id)
, range_(range)
, bearing_(bearing)
{} /* End of copy constructor */

Observation_model::~Observation_model() 
{} /* End of constructor */

long long
Observation_model::id() {
	return id_ ;
} /* End of get */

float
Observation_model::range() {
	return range_ ;
} /* End of range */

float
Observation_model::bearing() {
	return bearing_ ;
} /* End of bearing */