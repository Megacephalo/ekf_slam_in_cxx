#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

#include "document_processor.h"
#include "measurements_importer.h"
#if 0
TEST(Measurement_importer_test, test_readin_file) {
	std::string fileName = "../data/simple_sensor_data.dat" ;

	Measurement_importer z_importer ;
	z_importer.read_sensor_data(fileName) ;

	std::cout << "Acquired # state: " << z_importer.state_size() << std::endl ;
	ASSERT_EQ(z_importer.state_size(), 1) ;
}

TEST(Measurement_importer_test, test_read_all_entries_test) {
	std::string fileName = "../data/sensor_data.dat" ;

	Measurement_importer z_importer ;
	z_importer.read_sensor_data(fileName) ;

	std::cout << "Acquired # state: " << z_importer.state_size() << std::endl ;
}
#endif

TEST(Measurement_importer_test, get_states_test) {
	std::string fileName = "../data/short_sensor_data.dat" ;

	Measurement_importer z_importer ;
	z_importer.read_sensor_data(fileName) ;

	std::cout << "Acquired # state: " << z_importer.state_size() << std::endl ;

	state_set states = z_importer.get_states() ;
	
	std::cout << states << std::endl ;
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}