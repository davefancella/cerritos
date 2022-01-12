
add_executable(dadsteroids
    dasteroids.cpp
)
target_include_directories(dadsteroids PUBLIC
    src
    src/core
    src/widgets
)
target_link_libraries(dadsteroids
    cerritos
)
