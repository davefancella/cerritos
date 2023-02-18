
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

# copy dll on windows into binary directory
if(WIN32)
    add_custom_command(TARGET dadsteroids POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dadsteroids> $<TARGET_RUNTIME_DLLS:dadsteroids> $<TARGET_FILE_DIR:dadsteroids>
    )
endif(WIN32)
