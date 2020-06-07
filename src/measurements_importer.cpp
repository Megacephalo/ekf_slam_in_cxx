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
	unsigned int registration_count = 0 ;
	control u ;
	observations obs ; // vector of observation models
	while( std::getline(file, line) ) {
		// split the line into words
		std::vector<std::string> recv_line  = dproc_.split_string(line) ;

		
		// process the words
		if ( recv_line.front() == "ODOMETRY" ) {
			std::vector<std::string>::iterator it = recv_line.begin() + 1 ;

			float r1 = std::stof( *it ) ;
			float t = std::stof( *(it + 1) ) ;
			float r2 = std::stof( *(it + 2) ) ;
			u = std::shared_ptr<Wheel_odometry>( new Wheel_odometry(r1, t, r2) ) ;			
		}
		else if ( recv_line.front() == "SENSOR" ) {
			std::vector<std::string>::iterator it = recv_line.begin() + 1 ;

			long long id = std::stoll( *it ) ;
			float range = std::stof(*(it + 1)) ;
			float bearing = std::stof( *(it + 2) ) ;
			std::shared_ptr<Observation_model> observation ( new RadarReading(id, range, bearing) ) ;
			obs.push_back(observation) ;			
		}
		else {
			std::cerr << "Unrecognizable token\n" ;
			continue ;
		}
		registration_count ++ ;

		// when a state's control and observations are all registered
		if (registration_count == 3) {
			Sensor_Records record ;
			record.setMotion(u) ;
			record.setObs(obs) ;
			obs.clear() ;

			states_.push_back(record) ;

			registration_count = 0 ;
		}
	}	

	dproc_.close(file) ;
} /* End of read_sensor_data */

int
Measurement_importer::state_size() const {
	return (int)states_.size() ;
} /* End of state_size */

std::vector< Sensor_Records >
Measurement_importer::get_states() const {
	return states_ ;
} /* End of get_states */


