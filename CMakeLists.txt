cmake_minimum_required(VERSION 3.10)

project(MathSolverCxx CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GTest REQUIRED)

include_directories(include)

add_executable(run_tests 
    tests/MathSolverTest.cpp 
    src/MathSolver.cpp
)

target_link_libraries(run_tests 
    GTest::gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(run_tests)