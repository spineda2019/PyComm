cmake_minimum_required(VERSION 3.8)

project(libethernet DESCRIPTION "Ethernet Communication Library")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ETHERNET_SOURCES
    "src/EthernetMessenger.cpp")

add_library(ethernet ${MODULE_BUILD_TYPE} ${ETHERNET_SOURCES})

target_include_directories(ethernet PUBLIC "src/include")

if (MSVC)
  # for some reason this is required for MVSC, but this isn't valid or correct
  # otherwise?
  target_link_libraries(ethernet PRIVATE
    Boost::system
    Boost::asio)
else()
  target_link_libraries(ethernet PRIVATE
    ${Boost_LIBRARIES})
endif()

if (MSVC)
  # MSVC warns for things in system includes (e.g. STL, boost, etc.), so /WX
  # is not viable (/Wall already results in thousands of warnings)
  #$<$<CONFIG:Release>:/WX>
  target_compile_options(ethernet PRIVATE /W3)
else()
  target_compile_options(ethernet PRIVATE
    -W -Wall -pedantic -Wextra
    $<$<CONFIG:Release>:-Werror>
  )
endif()

install(TARGETS ethernet)
install(DIRECTORY "include/ethernet" DESTINATION "include")
