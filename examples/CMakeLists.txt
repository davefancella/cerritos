# set the project name
project(examples)

set(CMAKE_MODULE_PATH .)

# Generate examples

file(GLOB files "*.cmake")
foreach(file ${files})
  include(${file})
endforeach()


