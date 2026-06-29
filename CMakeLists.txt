cmake_minimum_required(VERSION 3.20)

project(MyGameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

file(GLOB_RECURSE SOURCES
    Engine/*.cpp
    Game/*.cpp
)

add_executable(Game ${SOURCES})

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Game/assets
        $<TARGET_FILE_DIR:Game>/assets
)

target_include_directories(Game PRIVATE
    .
    Game
    Engine
)

target_compile_definitions(Game PRIVATE
    GAME_ASSET_DIR="${CMAKE_SOURCE_DIR}/Game/assets/"
)

target_link_libraries(Game PRIVATE
    SDL2::SDL2
    SDL2_image::SDL2_image
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(Game PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
