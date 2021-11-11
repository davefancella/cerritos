cmake_minimum_required(VERSION 3.10)

# set the project name
project(examples)

# Generate examples
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
