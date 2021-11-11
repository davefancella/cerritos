cmake_minimum_required(VERSION 3.10)

# set the project name
project(cerritos VERSION 0.1.0)

# add the library
add_library(cerritos SHARED
    cerritos.cpp
    backend/sdl_backend.cpp
    core/object.cpp
    core/application.cpp
    core/event.cpp
    widgets/widget.cpp
    widgets/mainwindow.cpp
)

target_include_directories(cerritos PUBLIC
    ${SDL2_LIBRARIES}
    .
    backend
    core
    core/events
    widgets
)

target_link_libraries(cerritos ${SDL2_LIBRARIES})

# Setup the version header
configure_file(cerritos_version.h.in cerritos_version.h)
target_include_directories(cerritos PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


