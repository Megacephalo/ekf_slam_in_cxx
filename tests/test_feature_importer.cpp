#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>

#include "document_processor.h"
#include "feature_importer.h"

TEST(Feature_importer_test, test_import_from) {
	std::string fileName = "../data/world.dat" ;

	Feature_Importer importer ;
	importer.import_from(fileName) ;
	std::vector<MapPoint> landmarks = importer.landmarks() ;
	ASSERT_EQ( landmarks.size(), 9 ) ;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}