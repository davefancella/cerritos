cmake_minimum_required(VERSION 3.10)

# set the project name
project(cerritos VERSION 0.1.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


# add the library
add_library(cerritos SHARED
    src/cerritos.cpp
    src/core/object.cpp
    src/core/application.cpp
    src/widgets/mainwindow.cpp
)

target_include_directories(cerritos PUBLIC
    ${SDL2_LIBRARIES}
    src
    src/core
    src/widgets
)

target_link_libraries(cerritos ${SDL2_LIBRARIES})

add_executable(hello
    examples/hello.cpp
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
