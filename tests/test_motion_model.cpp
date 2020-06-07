#include <gtest/gtest.h>
#include <iostream>
#include <memory>

#include "motion_model.h"
#include "wheel_odometry.h"

TEST(Motion_model_test, test_inheritantce) {
	std::unique_ptr<Motion_model> odo (new Wheel_odometry()) ;
	ASSERT_EQ(odo->r1(), 0.) ;
	ASSERT_EQ(odo->t(), 0.) ;
	ASSERT_EQ(odo->r2(), 0.) ;
}

TEST(Motion_model_test, test_assign_arguments) {
	std::unique_ptr<Motion_model> odo (new Wheel_odometry(-0.01, 1, 0.01)) ;
	std::cout << "odo r1: " << odo->r1() << "\tt: " << odo->t() << "\tr2: " << odo->r2() << std::endl ;
	ASSERT_EQ(odo->r1(), (float)-0.01) ;
	ASSERT_EQ(odo->t(), 1) ;
	ASSERT_EQ(odo->r2(), (float)0.01) ;
}

TEST(Motion_model_test, operator_overloading_test) {
	std::unique_ptr<Motion_model> odo (new Wheel_odometry) ;
	std::cout << odo << std::endl ;

	std::shared_ptr<Motion_model> odo2 (new Wheel_odometry(-0.01, 1, 0.01)) ;
	std::cout << odo2 << std::endl ;
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}