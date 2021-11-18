cmake_minimum_required(VERSION 3.10)

# set the project name
project(examples)

# Generate examples

# Hello world
add_executable(hello
    hello.cpp
)
target_include_directories(hello PUBLIC
    ${SDL2_LIBRARIES}
    src
    src/core
    src/widgets
)
target_link_libraries(hello 
    cerritos
)

# Event Test
add_executable(eventTest
    eventTest.cpp
)
target_include_directories(eventTest PUBLIC
    ${SDL2_LIBRARIES}
    src
    src/core
    src/widgets
)
target_link_libraries(eventTest
    cerritos
)

# SDL Font Test
add_executable(showfont
    showfont.c
)
target_include_directories(showfont PUBLIC
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
)
target_link_libraries(showfont
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
)

# Font Test
add_executable(fontTest
    fontTest.cpp
)
target_include_directories(eventTest PUBLIC
    ${SDL2_LIBRARIES}
    src
    src/core
    src/widgets
)
target_link_libraries(fontTest
    cerritos
)

