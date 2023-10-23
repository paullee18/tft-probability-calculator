cmake_minimum_required(VERSION 3.10)

project(MyTests)

set(CMAKE_CXX_STANDARD 20)

# Add Google Test
include_directories("/Users/paul/googletest/include")
add_subdirectory("/Users/paul/googletest/" "googletest-build")

add_executable(MyTests test_main.cpp ../src/MatrixHandler.cpp ../src/ProbabilityCalculator.cpp ../src/config.cpp)

target_link_libraries(MyTests gtest gtest_main)
