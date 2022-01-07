# This file isn't used currently

cmake_minimum_required(VERSION 3.10)

# add the library
add_library(cerritos SHARED
    binreloc/binreloc.c
)

target_include_directories(cerritos PUBLIC
    .
    binreloc/
)

target_link_libraries(cerritos 
)


