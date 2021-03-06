#ifndef _DOCUMENT_PROCESSOR_H_
#define _DOCUMENT_PROCESSOR_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class Document_processor {
  public:
  	std::ifstream getFile(const std::string& fileName) ;
  	bool fileExist(const std::string& fileName) ;
  	bool fileCanOpen(const std::string& fileName) ;
  	void print_vect(const std::vector<std::string>& in_vect) ;
  	bool close(std::ifstream& file) ;

  	std::vector<std::string> split_string(const std::string& str, char delimiter = ' ') ;
} ; /* End of class */

#endif /* _DOCUMENT_PROCESSOR_H_ */