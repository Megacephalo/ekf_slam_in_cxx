#ifndef _MEASUREMENT_IMPORTER_H_
#define _MEASUREMENT_IMPORTER_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "document_processor.h"
#include "sensor_records.h"

typedef std::vector< Sensor_Records > state_set ;

class Measurement_importer {
  public:
  	Measurement_importer() ;
  	void read_sensor_data(const std::string& fileName) ;
  	int state_size() const ;
  	std::vector< Sensor_Records > get_states() const ;
  private:
  	std::vector< Sensor_Records > states_ ;
  	Document_processor dproc_ ;
  	
} ; /* End of class */
#endif /* _MEASUREMENT_IMPORTER_H_ */