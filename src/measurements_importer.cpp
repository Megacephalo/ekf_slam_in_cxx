#include "measurements_importer.h"

Measurement_importer::Measurement_importer()
{} /* End of default constructor */

void
Measurement_importer::read_sensor_data(const std::string& fileName) {
	if ( !dproc_.fileExist(fileName) ) {
		std::cerr << "The file does not exist.\n" ;
		return ;
	}

	if ( !dproc_.fileCanOpen(fileName) ) {
		std::cerr << "The file cannot be openned or is corrupted.\n" ;
		return ;
	}

	std::ifstream file = dproc_.getFile(fileName) ;
	std::string line ;
	while( std::getline(file, line) ) {
		// split the line into words
		std::vector<std::string> recv_line  = dproc_.split_string(line) ;

		// process the words
		if ( recv_line.front() == "ODOMETRY" ) {
			std::vector<std::string>::iterator it ;
			for (it = recv_line.begin() + 1 ; it != recv_line.end() ; ++it) {
				// std::cout << *it << " " ;
			}
			// std::cout << "\n" ;
		}
		else if ( recv_line.front() == "SENSOR" ) {
			std::vector<std::string>::iterator it ;
			for (it = recv_line.begin() + 1 ; it != recv_line.end() ; ++it) {
				// std::cout << *it << " " ;
			}
			// std::cout << "\n" ;
		}
		else {
			std::cerr << "Unrecognizable token\n" ;
			continue ;
		}
	}	

} /* End of read_sensor_data */

int
Measurement_importer::state_size() const {
	return (int)states_.size() ;
} /* End of state_size */

std::vector< Sensor_Records >
Measurement_importer::get_states() const {
	return states_ ;
} /* End of get_states */


