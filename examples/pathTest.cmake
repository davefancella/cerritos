
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
