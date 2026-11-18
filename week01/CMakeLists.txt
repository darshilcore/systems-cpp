cmake_minimum_required(VERSION 3.20)
project(week01 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # helps clangd and clang-tidy

add_compile_options(-Wall -Wextra -Wpedantic)

# Build each exercise as a separate program named after the file
file(GLOB EXERCISES CONFIGURE_DEPENDS exercises/*.cpp)
foreach(src ${EXERCISES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
    target_compile_options(${name} PRIVATE -fsanitize=address,undefined -g)
    target_link_options(${name} PRIVATE -fsanitize=address,undefined)
endforeach()