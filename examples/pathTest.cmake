
add_executable(pathTest
    pathTest.cpp
)
target_include_directories(pathTest PUBLIC
    src
    src/core
    src/widgets
)
target_link_libraries(pathTest
    cerritos
)

# copy dll on windows into binary directory
if(WIN32)
    add_custom_command(TARGET pathTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pathTest> $<TARGET_RUNTIME_DLLS:pathTest> $<TARGET_FILE_DIR:pathTest>
    )
endif(WIN32)
