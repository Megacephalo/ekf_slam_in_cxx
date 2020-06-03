#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "matplotlibcpp.h"

namespace plt = matplotlibcpp ;

TEST(Matplotlibcpp_test, minimal_plot_test) {
	plt::plot({1,3,2,4});
    plt::show();
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}