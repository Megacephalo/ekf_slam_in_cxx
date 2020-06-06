#ifndef _SENSOR_RECORDS_H_
#define _SENSOR_RECORDS_H_

#include <memory>
#include <vector>
#include <iostream>
#include <utility>

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

typedef std::shared_ptr<Motion_model> control ;
typedef std::vector< std::shared_ptr<Observation_model> > observations ;

class Sensor_Records {
  public:
  	Sensor_Records(const ObservationMode& obsM = RADAR, const MotionMode& odomM = WHEEL) ;
  	void setMotion(const control& motion_state) ;
  	void setObs(const observations& scans) ;
  	std::pair<control, observations> getState() const ;

  private:
  	std::shared_ptr<Observation_model> obs_ ;

  	control odom_ ;
  	observations scans_ ; // Observation_model*[] scans_
} ; /* End of class */

typedef std::vector<Sensor_Records> state_set ;

#endif /* _SENSOR_RECORDS_H_ */