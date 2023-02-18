add_executable(eventTest
    eventTest.cpp
)
target_include_directories(eventTest PUBLIC
    src
    src/core
    src/widgets
)
target_link_libraries(eventTest
    cerritos
)

# copy dll on windows into binary directory
add_custom_command(TARGET eventTest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:eventTest> $<TARGET_FILE_DIR:eventTest>
)