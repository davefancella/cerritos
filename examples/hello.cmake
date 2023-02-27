add_executable(hello
    hello.cpp
)
target_include_directories(hello PUBLIC
    src
    src/core
    src/widgets
)

target_link_libraries(hello 
    cerritos
)

# copy dll on windows into binary directory
if(WIN32)
    add_custom_command(TARGET hello POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hello> $<TARGET_RUNTIME_DLLS:hello> $<TARGET_FILE_DIR:hello>
    )
endif(WIN32)
