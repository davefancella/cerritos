cmake_minimum_required(VERSION 3.10)

# set the project name
project(cerritos VERSION 0.1.0)

# add the library
add_library(cerritos SHARED
    cerritos.cpp
    backend/sdl_backend.cpp
    backend/sdl_poll_hardware_events.cpp
    binreloc/binreloc.c
    core/application.cpp
    core/circle.cpp
    core/event.cpp
    core/events/eventreceiver.cpp
    core/font.cpp
    core/imagemanager.cpp
    core/map.cpp
    core/object.cpp
    core/path.cpp
    core/point.cpp
    core/rect.cpp
    core/sprite.cpp
    core/surface.cpp
    core/window.cpp
    widgets/layout.cpp
    widgets/mainwindow.cpp
    widgets/widget.cpp
)

target_include_directories(cerritos PUBLIC
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
    .
    backend
    core
    core/events
    core/events/hardware
    widgets
)

target_link_libraries(cerritos 
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    stdc++fs
    stdc++
)

# Setup the version header
configure_file(cerritos_version.h.in cerritos_version.h)
target_include_directories(cerritos PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


