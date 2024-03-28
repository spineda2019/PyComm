cmake_minimum_required(VERSION 3.8)

project(pycomm DESCRIPTION "Communication Module for Python")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(Python COMPONENTS Interpreter Development)

if(NOT Python_FOUND)
    message(FATAL "Python not found! Ensure it is installed")
else()
    message("Python include dirs found @ ${Python_INCLUDE_DIRS}")
endif()
    

set(PY_SOURCES
    "src/pycomm.c")

add_library(pycomm ${MODULE_BUILD_TYPE} ${PY_SOURCES})

set_target_properties(
    pycomm
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME "pycomm"
        LINKER_LANGUAGE C
    )

target_include_directories(pycomm PUBLIC "src/include" ${Python_INCLUDE_DIRS})

if (MSVC)
  # MSVC warns for things in system includes (e.g. STL, boost, etc.), so /WX
  # is not viable (/Wall already results in thousands of warnings)
  #$<$<CONFIG:Release>:/WX>
  target_compile_options(pycomm PRIVATE /W3)
else()
  target_compile_options(pycomm PRIVATE
    -W -Wall -pedantic -Wextra
    $<$<CONFIG:Release>:-Werror>
  )
endif()

install(TARGETS pycomm)
install(DIRECTORY "include/pycomm" DESTINATION "include")
