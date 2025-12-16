cmake_minimum_required(VERSION 3.14)
project(DifferentDigits)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(run_tests
    tests/test_digits.cpp
    src/digits.cpp
)

target_link_libraries(run_tests GTest::GTest GTest::Main)