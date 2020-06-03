#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "document_processor.h"

TEST(document_processor_test, test_import_document) {
	std::string fileName = "../data/simple_sensor_data.dat" ;
	Document_processor dproc ;

	ASSERT_TRUE( dproc.fileExist(fileName) ) ;
	ASSERT_TRUE( dproc.fileCanOpen(fileName)) ;

	std::ifstream file = dproc.getFile(fileName) ;
	std::string line ;
	while ( std::getline( file, line ) ) {
		std::cout << line << std::endl ;
	}
	std::cout << "\n\n" ;

	int counter = 0 ;
	while( std::getline( dproc.getFile(fileName), line ) && counter < 5 ) {
		std::cout << line << std::endl ;
		counter ++ ;
	}
	std::cout << "\n\n" ;
}

TEST(document_processor_test, test_print_vect) {
	std::vector<std::string> test = {"ODOMETRY", "1", "2", "3"} ;
	Document_processor dproc ;
	dproc.print_vect(test) ;
}

TEST(document_processor_test, test_split_string) {
	std::string testString = "I love EKF SLAM.\n" ;
	Document_processor dproc ;

	std::vector<std::string> out_vect = dproc.split_string(testString) ;
	ASSERT_EQ(out_vect.at(0), "I") ;
	ASSERT_EQ(out_vect.at(1), "love") ;
	ASSERT_EQ(out_vect.at(2), "EKF") ;
	ASSERT_EQ(out_vect.at(3), "SLAM.\n") ;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}