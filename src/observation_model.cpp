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

std::ostream&
operator << (std::ostream& os, const std::shared_ptr<Observation_model>& obs) {
	os << "Observation ID: " << std::left << std::setw(15) << obs->id() << "range: " << std::left << std::setw(15) << obs->range() << "bearing: " << std::left << std::setw(15) << obs->bearing() ;
	return os ;
} /* End of operator << overloading */

std::ostream&
operator << (std::ostream& os, const std::unique_ptr<Observation_model>& obs) {
	os << "Observation ID: " << std::left << std::setw(15) << obs->id() << "range: " << std::left << std::setw(15) << obs->range() << "bearing: " << std::left << std::setw(15) << obs->bearing() ;
	return os ;
} /* End of operator << overloading */