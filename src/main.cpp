#include <iostream>
#include <string>
#include <memory>  /* unique_ptr */
#include <sstream> /* stringstream */
#include <iomanip> /* setw, setfill */

#include "draw.h"
#include "measurements_importer.h"
#include "feature_importer.h"
#include "filter_base.h"
#include "ekf.h"

/* Function prototype */
void check_arguments(int argc, char** argv) ;

int main(int argc, char** argv) {
	std::cout << "EKF SLAM is launching.\n" ;

	try {
		check_arguments(argc, argv) ;	
	}
	catch(const char* err_msg) {
		std::cerr << err_msg << std::endl ;
		return -1 ;
	}


	std::string observation_dataset = argv[1] ;
	std::string world_dataset = argv[2] ;

	Measurement_importer measImporter ;
	measImporter.read_sensor_data(observation_dataset) ;

	Feature_Importer featImporter ;
	featImporter.import_from(world_dataset) ;

	Draw drawer ;

	std::unique_ptr<Filter_base> ekf_slam(new EKF) ;
	ekf_slam->initialize(featImporter.landmarks(), 3) ;

	state_set raw_states = measImporter.get_states() ;

	std::vector<Eigen::VectorXd> est_trajectory ;

	state_set::const_iterator it ;
	int i = 0 ;
	for (it = raw_states.begin() ; it != raw_states.end() ; it++) {
		Sensor_Records record = *it ;

		ekf_slam->execute(record) ;

		drawer.Clear() ;

		drawer.Plot_state( ekf_slam->getMean()
						 , ekf_slam->getCovariance()
						 , featImporter
						 , ekf_slam->get_observed_landmarks()
						 , record.getState().second ) ;

		est_trajectory.push_back(ekf_slam->getMean()) ;
		drawer.draw_trajectory(est_trajectory) ;

		drawer.Pause(0.005) ;



		std::stringstream ss ;
		ss << std::setfill('0') << std::setw(3) << i ;
		i++ ;
		drawer.Save("images/" + ss.str()) ;
	}
	std::cout << "Done!" << std::endl ;

	drawer.Show() ;

	return 0 ;
}


void check_arguments(int argc, char** argv) {
	std::string help_msg = "Usage: ./<This program> [path to sensor_dataset] [path to map dataset]" ;

	if (argc < 2) {
		std::cerr << help_msg << std::endl ;
		throw "Missing to designated two input datasets" ;
	}
	else if (argc < 3) {
		std::cerr << help_msg << std::endl ;
		throw "Missing to designated one more input dataset" ;
	}
	else {
		std::cout << "-------------------------------------------\n" ;
		std::cout << "Import sensor dataset from: " << argv[1] << std::endl ; 
		std::cout << "Import map dataset from: " << argv[2] << std::endl ;
		std::cout << "-------------------------------------------\n" ;
	}
} /* End of check_arguments */