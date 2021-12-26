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

