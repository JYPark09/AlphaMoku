# Target name
set(target AlphaMoku)

# Sources
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

# Build library
add_library(${target} STATIC ${sources})
