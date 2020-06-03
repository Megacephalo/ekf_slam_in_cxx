#ifndef _SENSOR_RECORDS_H_
#define _SENSOR_RECORDS_H_

#include <memory>
#include <vector>
#include <iostream>

#include "motion_model.h"
#include "observation_model.h"

#include "radarReading.h"
#include "wheel_odometry.h"

/**
This class collect the curent control and all observed landmarks in a single structure
**/
enum ObservationMode {
	RADAR,
	LIDAR,
	UNDETERMINED
} ;

enum MotionMode {
	WHEEL,
	VO,
	UNKNOWN
} ;


class Sensor_Records {
  public:
  	Sensor_Records(const ObservationMode& obsM = RADAR, const MotionMode& odomM = WHEEL) ;

  private:
  	std::shared_ptr<Observation_model> obs_ ;

  	std::vector< std::shared_ptr<Observation_model> > scans_ ; // Observation_model*[] scans_
  	std::shared_ptr<Motion_model> odom_ ;
} ; /* End of class */

#endif /* _SENSOR_RECORDS_H_ */