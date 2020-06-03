#ifndef _RADAR_READING_H_
#define _RADAR_READING_H_

#include "observation_model.h"

struct RadarReading : public Observation_model {
	RadarReading(const long long& id = 0, const float& range = 0., const float& bearing = 0.) ;
	~RadarReading() ;
} ; /* End of class */

#endif /* _RADAR_READING_H_ */