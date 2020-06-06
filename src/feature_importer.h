#ifndef _FEATURE_IMPORTER_H_
#define _FEATURE_IMPORTER_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

#include "document_processor.h"
#include "map_point.h"

class Feature_Importer {
  public:
  	Feature_Importer() ;
  	void import_from (const std::string& fileName) ;
  	LandmarkSet landmarks() const ;
  	int landmark_size() const ;
  private:
  	std::vector<MapPoint> landmarks_ ;
  	std::unique_ptr<Document_processor> dproc_ ;
} ; /* End of class */

#endif /*  _FEATURE_IMPORTER_H_ */