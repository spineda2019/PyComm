cmake_minimum_required(VERSION 3.8)

project(test DESCRIPTION "Quick Test Directory")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_SOURCES
    "main.cpp")

add_executable(test ${TEST_SOURCES})

target_link_libraries(test serial ethernet)

