#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>

#include "document_processor.h"

TEST(document_processor_test, test_import_document) {
	std::string fileName = "../data/simple_sensor_data.dat" ;
	Document_processor dproc ;

	ASSERT_TRUE( dproc.fileExist(fileName) ) ;

	ASSERT_TRUE( dproc.fileCanOpen(fileName)) ;

	std::string line ;
	while( std::getline(dproc.getFile(fileName), line) ) {
		std::cout << line << std::endl ;
	}
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}