
add_executable(fontTest
    fontTest.cpp
)
target_include_directories(fontTest PUBLIC
    src
    src/core
    src/widgets
)
target_link_libraries(fontTest
    cerritos
)

# copy dll on windows into binary directory
if(WIN32)
    add_custom_command(TARGET fontTest POST_BUILD
         COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:fontTest> $<TARGET_RUNTIME_DLLS:fontTest> $<TARGET_FILE_DIR:fontTest>
    )
endif(WIN32)
