cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML 3 REQUIRED COMPONENTS Graphics)

add_executable(main src/main.cpp
    src/engine/Application.cpp
    src/engine/Application.hpp
    src/engine/Scene.hpp
    src/scenes/TestScene.cpp
    src/scenes/TestScene.hpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)