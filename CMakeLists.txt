cmake_minimum_required(VERSION 3.16)
project(Template)

set(CMAKE_CXX_STANDARD 17)

# Source files
add_executable(Template
    Source.cpp
    base.cpp
    base.hpp
    player.cpp
    player.hpp
    enemyBase.cpp
    enemybase.hpp
    animPlayer.cpp
    animPlayer.hpp
    collosion.hpp
)

# Find Raylib
find_package(raylib REQUIRED)

target_link_libraries(Template raylib)

# Copy assets to build directory
add_custom_command(TARGET Template POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Warrior $<TARGET_FILE_DIR:Template>/Warrior
)
