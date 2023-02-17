cmake_minimum_required(VERSION 3.10)

# set the project name
project(cerritos VERSION 0.1.0)

# Thirdparty sources
# currently not used in this form
#add_subdirectory(thirdparty/boost/libs/filesystem)

# add the library
add_library(cerritos SHARED
    cerritos.cpp
    backend/sdl_backend.cpp
    backend/sdl_poll_hardware_events.cpp
    core/application.cpp
    core/circle.cpp
    core/clock.cpp
    core/event.cpp
    core/events/eventreceiver.cpp
    core/font.cpp
    core/imagemanager.cpp
    core/map.cpp
    core/object.cpp
    core/path.cpp
    core/rect.cpp
    core/sound.cpp
    core/sprite.cpp
    core/surface.cpp
    core/window.cpp
    core/collide.cpp
    thirdparty/binreloc/binreloc.c
    widgets/layout.cpp
    widgets/mainwindow.cpp
    widgets/widget.cpp
)

# Setup the version header
configure_file(cerritos_version.h.in cerritos_version.h)
target_include_directories(cerritos PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

install(TARGETS cerritos 
    DESTINATION lib/cerritos)

#    cerritos_version.h  # This is obviously very important
install(FILES 
    cerritos.h
    backend/sdl_backend.h
    core/application.h
    core/circle.h
    core/event.h
    core/events/eventreceiver.h
    core/font.h
    core/imagemanager.h
    core/map.h
    core/object.h
    core/path.h
    core/point.h
    core/rect.h
    core/sound.h
    core/sprite.h
    core/surface.h
    core/window.h
    thirdparty/binreloc/binreloc.c
    widgets/layout.h
    widgets/mainwindow.h
    widgets/widget.h
    DESTINATION include
)

target_include_directories(cerritos BEFORE PUBLIC
    .
    backend
    core
    core/events
    core/events/hardware
    thirdparty/boost
    thirdparty/binreloc
    thirdparty/tclap
    widgets
)

target_include_directories(cerritos SYSTEM PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${SDL2TTF_INCLUDE_DIRS}
)

target_link_libraries(cerritos PUBLIC
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
    $<$<AND:$<CXX_COMPILER_ID:GNU>,$<VERSION_LESS:$<CXX_COMPILER_VERSION>,9.1>>:stdc++fs>
)

if(OPENAL_FOUND)
    target_include_directories(cerritos SYSTEM PUBLIC
        ${OPENAL_INCLUDE_DIR}
        ${ALUT_INCLUDE_DIR}
    )

    target_link_libraries(cerritos PUBLIC
        ${OPENAL_LIBRARY}
        ${ALUT_LIBRARY}
    )
endif(OPENAL_FOUND)

install(TARGETS cerritos
        EXPORT cerritos
        LIBRARY DESTINATION lib
       ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)
        
        
