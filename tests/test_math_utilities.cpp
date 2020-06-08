#include <gtest/gtest.h>
#include <iostream>
#include <cmath>

#include "math_utilities.h"

class math_utilities_test : public ::testing::Test {
  protected:
  	Math_utilities math_ ;
} ; /* End of fixture */

TEST_F(math_utilities_test, deg2rad_test) {
	ASSERT_EQ(math_.deg2rad(180.), (float)M_PI) ;
	ASSERT_EQ(math_.deg2rad(0.), 0) ;
	ASSERT_EQ(math_.deg2rad(180), (float)M_PI) ;
	ASSERT_EQ(math_.deg2rad(0), 0) ;
	ASSERT_EQ(math_.deg2rad(360.), (float)(2 * M_PI)) ;
	ASSERT_EQ(math_.deg2rad(540), (float)9.42477796) ;
}

TEST_F(math_utilities_test, rad2deg_test) {
	ASSERT_EQ(math_.rad2deg(M_PI), 180.) ;
	ASSERT_EQ(math_.rad2deg(0), 0) ;
	ASSERT_EQ(math_.rad2deg(2 * M_PI), 360) ;
	ASSERT_EQ(math_.rad2deg(M_PI / 2), 90) ;
	ASSERT_EQ(math_.rad2deg((float)9.42477796), 540) ;
}

TEST_F(math_utilities_test, normalize_angle_test) {
	ASSERT_EQ((int)math_.normalize_angle(7.85398163), (int)(M_PI / 2) ) ;
	ASSERT_EQ((int)math_.normalize_angle(-7.85398163), -(int)(M_PI / 2) ) ;
	// ASSERT_EQ(math_.normalize_angle(), ) ;
	// ASSERT_EQ(math_.normalize_angle(), ) ;
	// ASSERT_EQ(math_.normalize_angle(), ) ;
}

TEST_F(math_utilities_test, normalize_angle_to_2pi_test) {
	ASSERT_EQ(math_.normalize_angle_to_2pi((float)9.42477796), (float)M_PI) ;
	ASSERT_EQ(math_.normalize_angle_to_2pi((float)14.1371669), (float)(M_PI / 2)) ;
	ASSERT_EQ((int)math_.normalize_angle_to_2pi(-M_PI) , (int)3.14159 ) ; // this is weird!!
	ASSERT_EQ(math_.normalize_angle_to_2pi(-M_PI / 2), (float)4.71238898) ;
}

TEST_F(math_utilities_test, normalize_bearing_test) {
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}