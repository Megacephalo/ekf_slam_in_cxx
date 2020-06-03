cmake_minimum_required(VERSION 3.1)
project(EKF_SLAM)
ADD_DEFINITIONS(-std=c++11) # C++ 11 is required
set (CMAKE_CXX_STANDARD 11)

# set the compilation mode to Debug (non-optimized code with debug symbols)
# set(CMAKE_BUILD_TYPE Debug)

# set the compilation mode to RelWithDebInfo (optimized code with debug symbols
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(src)
include_directories(src/drawing_utils)

# Import Eigen libraries
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Import Python.h
find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)
message(STATUS "Python version: ${PYTHONLIBS_VERSION_STRING}")
# Message out python and numpy path
message(STATUS "PYTHON_INCLUDE_DIR: ${PYTHON_INCLUDE_DIR}")

add_definitions(-DMATPLOTLIBCPP_PYTHON_HEADER=Python.h)
include_directories(${PYTHON_INCLUDE_DIR})



# Libraries
## Kalman filter SLAM
add_library(KalmanFilter_SLAM
	src/observation_model.cpp
	src/radarReading.cpp
	src/motion_model.cpp
	src/wheel_odometry.cpp
	src/sensor_records.cpp
	src/document_processor.cpp
	src/measurements_importer.cpp
	src/feature_importer.cpp

)
target_link_libraries(KalmanFilter_SLAM
	Eigen3::Eigen
)

## Drawing utils library
set (Drawing_utils
	src/drawing_utils
)
add_library(drawing_utils
	${Drawing_utils}/matplotlibcpp.cpp
	${Drawing_utils}/chisquare.cpp
	${Drawing_utils}/draw.cpp
)
target_link_libraries(drawing_utils
	Eigen3::Eigen
	${PYTHON_LIBRARIES}

	KalmanFilter_SLAM
)


# Executables
add_executable(EKF_SLAM_in_cxx
	src/main.cpp
)

target_link_libraries(EKF_SLAM_in_cxx
	KalmanFilter_SLAM
	drawing_utils
)


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
## Observation model
add_executable(test_observation_model
	tests/test_observation_model.cpp
)
target_link_libraries(test_observation_model
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## Motion model
add_executable(test_motion_model
	tests/test_motion_model.cpp
)
target_link_libraries(test_motion_model
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## sensor_records
add_executable(test_sensor_records
	tests/test_sensor_records.cpp
)
target_link_libraries(test_sensor_records
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## map point
add_executable(test_map_point
	tests/test_mapPoint.cpp
)
target_link_libraries(test_map_point
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## Measurement import
add_executable(test_measurement_import
	tests/test_measurement_import.cpp
)
target_link_libraries(test_measurement_import
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## document_processor
add_executable(test_document_processor
	tests/test_document_processor.cpp
)
target_link_libraries(test_document_processor
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## feature_importer
add_executable(test_feature_importer
	tests/test_feature_importer.cpp
)
target_link_libraries(test_feature_importer
	${GTEST_LIBRARIES}
	pthread # Required

	KalmanFilter_SLAM
)

## drawer
add_executable(test_drawer
	tests/test_drawer.cpp
)
target_link_libraries(test_drawer
	${GTEST_LIBRARIES}
	pthread # Required

	Eigen3::Eigen
	drawing_utils
)
