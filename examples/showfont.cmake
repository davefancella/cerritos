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

