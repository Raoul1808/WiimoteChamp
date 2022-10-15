cmake_minimum_required(VERSION 3.23)
project(WiimoteChamp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/SDL)
add_subdirectory(external/glad)

add_executable(WiimoteChamp main.cpp)
target_link_libraries(WiimoteChamp PRIVATE SDL2main SDL2 Glad)
