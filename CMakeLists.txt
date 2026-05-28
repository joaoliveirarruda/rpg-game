cmake_minimum_required(VERSION 3.20)
project(rpg_combat CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Warnings em todos os builds
add_compile_options(-Wall -Wextra -Wpedantic)

# Sanitizers em modo Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address,undefined -g)
    add_link_options(-fsanitize=address,undefined)
endif()

add_executable(rpg_combat
    src/main.cpp
    src/weapon.cpp
    src/inventory.cpp
    src/ability.cpp
    src/character.cpp
)

target_include_directories(rpg_combat PRIVATE src)
