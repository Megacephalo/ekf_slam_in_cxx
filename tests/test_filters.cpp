#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include <cstdio>
#include <cstdlib>  /* exit, EXIT_FAILURE */

#include "measurements_importer.h"
#include "feature_importer.h"
#include "filter_base.h"
#include "ekf.h"
#include "odometry_motion_model.h"

TEST(Odometry_Motion_Model_test, init_covariance_test) {
	Odometry_Motion_Model odom(9, 3) ;
	std::cout << "Initial covariance:\n" << odom.getCovariance() << std::endl ;
}

TEST(EKF_test, initialize_test) {
	std::unique_ptr<Filter_base> ekf (new EKF) ;

	std::string observation_dataset = "../data/short_sensor_data.dat" ;
	// std::string observation_dataset = "../data/medium_size_sensor_data.dat" ;
	std::string world_dataset = "../data/world.dat" ;

	const auto p1 = std::chrono::system_clock::now() ;
	std::ostringstream os ;
	os << std::chrono::duration_cast<std::chrono::seconds>(
                   p1.time_since_epoch()).count() ;
	std::string now_epoch = os.str() ;
	std::string output_debug_file = "../log/debug_" + now_epoch + ".txt" ;
	std::cout << "Ouput debug info to " << output_debug_file << std::endl ;
	FILE* logFile ;
	logFile = std::freopen( output_debug_file.c_str(), "w", stdout ) ;
	if (!logFile) {
		std::cerr << "Cannot create the log file " << output_debug_file << std::endl ;
		exit(EXIT_FAILURE) ;
	}

	Measurement_importer measImporter ;
	measImporter.read_sensor_data(observation_dataset) ;

	Feature_Importer featImporter ;
	featImporter.import_from(world_dataset) ;
	std::cout << "Imported " << featImporter.landmark_size() << " landmarks." << std::endl ;

	std::unique_ptr<Filter_base> ekf_slam(new EKF) ;
	ekf_slam->initialize(featImporter.landmarks(), 3) ;

	state_set raw_states = measImporter.get_states() ;
	// std::cout << "raw states:\n" << raw_states << std::endl ;

	for (unsigned int i = 0 ; i < measImporter.state_size() ; i++) {
		std::cout << "======================\n" ;
		std::cout << "state #" << i + 1 << std::endl ;

		Sensor_Records record = raw_states.at(i) ;

		std::cout << record << std::endl ;

		ekf_slam->execute(record) ;
		std::cout << "EKF estimate: mu = \n" << ekf_slam->getMean() << "\tSigma =\n" << ekf_slam->getCovariance() << std::endl ; 
		std::cout << "======================\n" ;

	}
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}