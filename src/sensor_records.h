#ifndef _SENSOR_RECORDS_H_
#define _SENSOR_RECORDS_H_

#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>
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

class Sensor_Records ;
typedef std::vector<Sensor_Records> state_set ;

class Sensor_Records {
  public:
  	Sensor_Records(const ObservationMode& obsM = RADAR, const MotionMode& odomM = WHEEL) ;
  	void setMotion(const control& motion_state) ;
  	void setObs(const observations& scans) ;
  	std::pair<control, observations> getState() const ;

    friend std::ostream& operator << (std::ostream& os, const Sensor_Records& record) ;

  private:
  	std::shared_ptr<Observation_model> obs_ ;

  	control odom_ ;
  	observations scans_ ; // Observation_model*[] scans_
} ; /* End of class */

std::ostream& operator << (std::ostream& os, const Sensor_Records& record) ;
std::ostream& operator << (std::ostream& os, const state_set& states) ;
std::ostream& operator << (std::ostream& os, const observations& obs) ;
#endif /* _SENSOR_RECORDS_H_ */