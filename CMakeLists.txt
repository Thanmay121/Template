cmake_minimum_required(VERSION 3.16)
project(Template)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake to find the raylib package installed via vcpkg
# Adding CONFIG is the key for vcpkg compatibility
find_package(raylib CONFIG REQUIRED)

# Source files (Make sure the filenames match exactly, e.g., enemyBase vs enemybase)
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

# Link the raylib library to your executable
target_link_libraries(Template PRIVATE raylib)

# Copy assets to build directory
add_custom_command(TARGET Template POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Warrior" "$<TARGET_FILE_DIR:Template>/Warrior"
)