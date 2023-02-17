if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
message(FATAL_ERROR “In-source build detected!”)
endif()

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(cerritos VERSION 0.1.0)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

option(USE_CONAN "Use Conan" OFF)
if(USE_CONAN)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif(USE_CONAN)

#include(sdl)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(OpenAL)

# The actual cerritos sources
add_subdirectory(src)
# support libraries in thirdparty

# Build documentation
option(BUILD_DOC "Build documentation" ON)
option(USE_SDL "Use SDL" ON)

if(USE_SDL)
    target_compile_definitions(cerritos PUBLIC USING_SDL)
endif(USE_SDL)

target_compile_definitions(cerritos PUBLIC BOOST_NO_CXX11_SCOPED_ENUMS)

if(OPENAL_FOUND)
find_library(ALUT_LIBRARY
	NAMES
	alut
	HINTS
	lib
	lib64
	PATHS
  /usr
	/usr/local
	/opt/local
	/sw)
endif(OPENAL_FOUND)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Configuring documentation")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_subdirectory(examples)
