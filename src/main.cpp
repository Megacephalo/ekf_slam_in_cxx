#include <iostream>
#include <string>
#include <sstream> /* stringstream */
#include <iomanip> /* setw, setfill */

#include "draw.h"
#include "measurements_importer.h"
#include "feature_importer.h"

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
	std::cout << "Imported " << featImporter.landmark_size() << " landmarks." << std::endl ;

	Draw drawer ;

	// TODO EKF SLAM

	state_set raw_states = measImporter.get_states() ;
	for (int i = 0 ; i < measImporter.state_size() ; i++) {
		state_set::const_iterator it = raw_states.begin() + i ;

		drawer.Clear() ;
		drawer.Pause() ;
		std::stringstream ss ;
		// ss << std::setfill('0') << std::setw(3) << i ;
		// drawer.Save("../images/" + ss.str()) ;
	}
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