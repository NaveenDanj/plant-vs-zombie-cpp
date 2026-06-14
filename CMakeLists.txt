cmake_minimum_required(VERSION 3.20)

project(MyGameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES
    Engine/*.cpp
    Game/*.cpp
)

add_executable(Game ${SOURCES})

target_include_directories(Game PRIVATE
    .
)

target_link_libraries(Game PRIVATE
    SDL2::SDL2
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(Game PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()