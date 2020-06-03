#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>

#include "map_point.h"

TEST(MapPoint_test, print_overloading) {
	MapPoint mapPt ;
	// test initial values
	std::cout << mapPt << std::endl ;

	// Specify values
	mapPt.id = 123 ;
	mapPt.x = 3.14159 ;
	mapPt.y = 1.1429 ;

	std::cout << mapPt << std::endl ;	
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}