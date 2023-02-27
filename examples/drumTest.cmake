add_executable(drumTest
    drumTest.cpp
)
target_include_directories(drumTest PUBLIC
    src
    src/core
    src/widgets
)

target_link_libraries(drumTest 
    cerritos
)

# copy dll on windows into binary directory
if(WIN32)
    add_custom_command(TARGET drumTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:drumTest> $<TARGET_RUNTIME_DLLS:drumTest> $<TARGET_FILE_DIR:drumTest>
    )
endif(WIN32)
