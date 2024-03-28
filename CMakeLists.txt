################################################################################
#                              Boilerplate Setup                               #
################################################################################
cmake_minimum_required(VERSION 3.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project("PyComm" CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

################################################################################
#                                  Build Type                                  #
################################################################################
option(BUILD_STATIC "Build static libraries rather than shared" OFF)

if(BUILD_STATIC)
    message("Building libraries as static libs")
    set(MODULE_BUILD_TYPE STATIC)
else()
  message("Building libraries as shared libs")
  set(MODULE_BUILD_TYPE SHARED)
endif()

################################################################################
#                                Boost Lookup                                  #
################################################################################
include(FetchContent)

find_package(Boost COMPONENTS system)
if (NOT Boost_FOUND)
  message(FATAL "Please ensure boost is installed")
endif()

message("Boost Include Directory Found At: ${Boost_INCLUDE_DIR}")

################################################################################
#                                Sub Libraries                                 #
################################################################################
add_subdirectory("ethernet")
add_subdirectory("serial")
add_subdirectory("python_module")
add_subdirectory("test")
