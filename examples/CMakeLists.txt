# set the project name
project(examples)

set(CMAKE_MODULE_PATH .)

# Generate examples

# Hello world
include(hello.cmake)

# Event Test
include(eventTest.cmake)

# SDL Font Test.  Only build this if you need to test SDL_ttf.
#include(showfont.cmake)

# Font Test
include(fontTest.cmake)

