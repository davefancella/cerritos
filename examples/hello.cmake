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

