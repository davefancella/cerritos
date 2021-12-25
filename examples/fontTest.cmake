
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
