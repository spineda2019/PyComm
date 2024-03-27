cmake_minimum_required(VERSION 3.8)

project(libserial DESCRIPTION "Serial Communication Library")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SERIAL_SOURCES
    "src/SerialMessenger.cpp")

add_library(serial ${MODULE_BUILD_TYPE} ${SERIAL_SOURCES})

target_include_directories(serial PUBLIC "src/include")

if (MSVC)
  # for some reason this is required for MVSC, but this isn't valid or correct
  # otherwise?
  target_link_libraries(serial PRIVATE
    Boost::system
    Boost::asio)
else()
  target_link_libraries(serial PRIVATE
    ${Boost_LIBRARIES})
endif()

if (MSVC)
  # MSVC warns for things in system includes (e.g. STL, boost, etc.), so /WX
  # is not viable (/Wall already results in thousands of warnings)
  #$<$<CONFIG:Release>:/WX>
  target_compile_options(serial PRIVATE /W3)
else()
  target_compile_options(serial PRIVATE
    -W -Wall -pedantic -Wextra
    $<$<CONFIG:Release>:-Werror>
  )
endif()

install(TARGETS serial)
install(DIRECTORY "include/serial" DESTINATION "include")
