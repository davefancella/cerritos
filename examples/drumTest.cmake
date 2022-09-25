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
