cmake_minimum_required(VERSION 3.7)
project(Testing-Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        tests/gtest.cpp src/Simulator.h src/Server.h src/Visitor.h tests/VisitoTest.h tests/gtest_fixture.cpp)
add_executable(Testing-Project ${SOURCE_FILES})

add_subdirectory(tests/lib/googletest/)
include_directories(tests/lib/googletest/googletest/include)
include_directories(tests/lib/googletest/googlemock/include)

target_link_libraries(Testing-Project gtest gtest_main)