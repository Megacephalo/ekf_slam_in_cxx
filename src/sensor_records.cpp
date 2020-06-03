#include "sensor_records.h"

Sensor_Records::Sensor_Records(const ObservationMode& obsM, const MotionMode& odomM)
{
	// Observation mode
	switch(obsM) {
		case ObservationMode::RADAR:
			std::cout << "Switch to RADAR scan data\n" ;
			obs_ = std::shared_ptr<RadarReading>(new RadarReading) ;
			break ;
		case ObservationMode::LIDAR:
			std::cout << "Switch to LIDAR scan data\n" ;
			// TODO
			break ;
		default:
			break ;
	} /* End of switch loop */

	switch(odomM) {
		case MotionMode::WHEEL:
			std::cout << "Swtich to Wheel odometry\n" ;
			odom_ = std::shared_ptr<Wheel_odometry>(new Wheel_odometry()) ;
			break ;
		case MotionMode::VO:
			std::cout << "Switch to visual odometry\n" ;
			// TODO
			break ;
		default:
			break ;
	} /* End of switch loop */
} /* End of default constructor */