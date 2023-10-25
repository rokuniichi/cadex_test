project(curves_lib)

set(sources
  src/circle.cpp
  src/curve.cpp
  src/curve_generator.cpp
  src/ellipse.cpp
  src/helix.cpp
  src/vector3d.cpp
)

# Creating a .dll library
add_library(curves_lib SHARED
  ${sources}
)

target_include_directories(curves_lib
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
