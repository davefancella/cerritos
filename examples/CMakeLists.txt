cmake_minimum_required(VERSION 3.10)

# set the project name
project(examples)

# Generate examples
add_executable(hello
    hello.cpp
)
add_executable(eventTest
    eventTest.cpp
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

target_include_directories(eventTest PUBLIC
    ${SDL2_LIBRARIES}
    src
    src/core
    src/widgets
)

target_link_libraries(eventTest
    cerritos
)
