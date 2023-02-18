add_executable(spriteTest
    spriteTest.cpp
)
target_include_directories(spriteTest PUBLIC
    src
    src/core
    src/widgets
)

target_link_libraries(spriteTest 
    cerritos
)

# copy dll on windows into binary directory
add_custom_command(TARGET spriteTest POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:spriteTest> $<TARGET_FILE_DIR:spriteTest>
)