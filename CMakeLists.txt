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

find_package(Boost 1.81.0 COMPONENTS system)
if (NOT Boost_FOUND)
  set(BOOST_INCLUDE_LIBRARIES system asio)
  set(BOOST_ENABLE_CMAKE ON)
  if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
  endif()
  FetchContent_Declare(Boost
    SYSTEM
    URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.tar.gz
    URL_HASH "SHA1=f71f661f893f39b7b82d66c54980349716f874a2"
  )
  FetchContent_GetProperties(Boost)
  if(NOT Boost_POPULATED)
    message(STATUS "Fetching Boost")
    message(STATUS "Downloading boost may take a while!")
    FetchContent_MakeAvailable(Boost)
  endif()
endif()

################################################################################
#                                Sub Libraries                                 #
################################################################################
add_subdirectory("ethernet")
add_subdirectory("serial")
# add_subdirectory("python_module")
