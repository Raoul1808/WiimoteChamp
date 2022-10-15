cmake_minimum_required(VERSION 3.23)
project(WiimoteChamp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/SDL)
add_subdirectory(external/glad)
add_subdirectory(external/imgui-cmake)

add_executable(WiimoteChamp src/main.cpp src/window.cpp src/imgui_impl/imgui_impl_opengl3.cpp src/imgui_impl/imgui_impl_sdl.cpp)
target_link_libraries(WiimoteChamp PRIVATE SDL2main SDL2 Glad ImGui)
