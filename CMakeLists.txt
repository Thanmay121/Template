cmake_minimum_required(VERSION 3.16)
project(Template)

set(CMAKE_CXX_STANDARD 17)

# Auto-detect vcpkg toolchain via VCPKG_ROOT environment variable
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

find_package(raylib CONFIG REQUIRED)

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
    sfx.hpp
    sfx.cpp
    camera.hpp
    camera.cpp
    collosion.hpp
    collosion.cpp
)

target_link_libraries(Template PRIVATE raylib)

if(WIN32)
    target_link_libraries(Template PRIVATE winmm)
endif()

add_custom_command(TARGET Template POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Warrior" "$<TARGET_FILE_DIR:Template>/Warrior"
)
# Copy maps folder
add_custom_command(TARGET Template POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/maps" "$<TARGET_FILE_DIR:Template>/maps")
