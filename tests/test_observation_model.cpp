#include <gtest/gtest.h>
#include <iostream>
#include <memory>

#include "observation_model.h"
#include "radarReading.h"

TEST(observation_model_test, test_inheritance) {
	std::unique_ptr<Observation_model> obs (new RadarReading() ) ;
	std::cout << "radar beam id: " << obs->id() << "\trange: " << obs->range() << "\tbearing: " << obs->bearing() << std::endl ;
	ASSERT_EQ(obs->id(), 0) ;
	ASSERT_EQ(obs->range(), 0.) ;
	ASSERT_EQ(obs->bearing(), 0.) ;
}

TEST(observation_model_test, test_constructor) {
	std::unique_ptr<Observation_model> obs (new RadarReading(1, 2., 3.)) ;
	std::cout << "radar beam id: " << obs->id() << "\trange: " << obs->range() << "\tbearing: " << obs->bearing() << std::endl ;
	ASSERT_EQ(obs->id(), 1) ;
	ASSERT_EQ(obs->range(), 2.) ;
	ASSERT_EQ(obs->bearing(), 3.) ;	
}

TEST(observation_model_test, anomally_test) {
	std::unique_ptr<Observation_model> obs (new RadarReading(-100, 2., 3.)) ;
	std::cout << "radar beam id: " << obs->id() << "\trange: " << obs->range() << "\tbearing: " << obs->bearing() << std::endl ;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}