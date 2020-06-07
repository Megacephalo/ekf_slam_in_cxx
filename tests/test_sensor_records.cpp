#include <gtest/gtest.h>
#include <iostream>
#include <memory>

#include "sensor_records.h"
#include "motion_model.h"
#include "wheel_odometry.h"
#include "observation_model.h"
#include "radarReading.h"

TEST(Sensor_Records_test, test_switch_mode) {
	std::cout << "sensor record 1\n" ;
	Sensor_Records sensorRecord ;

	std::cout << "sensor record 2\n" ;
	Sensor_Records sensorRecord2(LIDAR) ;

	std::cout << "sensor record 3\n" ;
	Sensor_Records sensorRecord3(RADAR, VO) ;

	std::cout << "sensor record 4\n" ;
	Sensor_Records sensorRecord4(LIDAR, VO) ;
}

TEST(Sensor_Records_test, operator_overloading_test) {
	Sensor_Records sensorRecord ;
	std::cout << sensorRecord << std::endl ;
}

TEST(Sensor_Records_test, real_input_operator_output_test) {
	control u(new Wheel_odometry) ;

	std::shared_ptr<Observation_model> z1(new RadarReading(0, 1.4128, 2.765)) ;
	std::shared_ptr<Observation_model> z2(new RadarReading(1, 2.129, 3.14159)) ;
	std::shared_ptr<Observation_model> z3(new RadarReading(2, 3.986, 4.65)) ;

	observations obs ;
	obs.push_back(z1) ;
	obs.push_back(z2) ;
	obs.push_back(z3) ;

	Sensor_Records record ;
	record.setMotion(u) ;
	record.setObs(obs) ;

	std::cout << record << std::endl ;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}