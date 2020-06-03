#include "radarReading.h"

RadarReading::RadarReading( const long long& id
						  , const float& range
						  , const float& bearing) 
: Observation_model(id, range, bearing)
{} /* End of constructor */

RadarReading::~RadarReading() 
{} /* End of destructor */

