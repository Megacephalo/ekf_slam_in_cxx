#include <gtest/gtest.h>
#include <iostream>
#include <memory>

#include "sensor_records.h"

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

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}