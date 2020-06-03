#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>

#include "document_processor.h"
#include "measurements_importer.h"

TEST(Measurement_importer_test, test_readin_file) {
	// std::string fileName = "../data/simple_sensor_data.dat" ;

	// Measurement_importer z_importer ;
	// z_importer.read_sensor_data(fileName) ;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}