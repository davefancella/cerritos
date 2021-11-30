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

