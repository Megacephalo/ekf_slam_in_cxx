#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "filter_base.h"
#include "ekf.h"

#include "sensor_records.h"

TEST(EKF_test, initialize_test) {
	// std::unique_ptr<Filter_base> ekf (new EKF) ;

	// state_set states ;
	// Sensor_Records rec1, rec2, rec3, rec4 ;

	// states.push_back(rec1) ;
	// states.push_back(rec2) ;
	// states.push_back(rec3) ;
	// states.push_back(rec4) ;

	// ekf->initialize(states) ;
	// ekf->execute() ;

	// Filter_base* kf
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}