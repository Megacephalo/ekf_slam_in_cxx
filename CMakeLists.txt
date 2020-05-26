cmake_minimum_required(VERSION 3.1)
project(IMDB_search)
ADD_DEFINITIONS(-std=c++11) # C++ 11 is required
set (CMAKE_CXX_STANDARD 11)

# set the compilation mode to Debug (non-optimized code with debug symbols)
# set(CMAKE_BUILD_TYPE Debug)

# set the compilation mode to RelWithDebInfo (optimized code with debug symbols
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})

# Import Eigen libraries
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

## Remeber to include Eigen in target_link_libraries as
#target_link_libraries(example
#    Eigen3::Eigen
#)


# Libraries


# Executables



# UNIT TESTS
# ~~~~~~~~~~
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(tests)

## Target_link_libraries must include
# ${GTEST_LIBRARIES}
# pthread # Required

# Test executables start here