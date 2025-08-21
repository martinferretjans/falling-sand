cmake_minimum_required(VERSION 3.31)
project(falling_sand)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/raylib-5.5)
include_directories(external/raylib-5.5/src)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(falling_sand "${SOURCES}")

target_link_libraries(falling_sand PRIVATE raylib)