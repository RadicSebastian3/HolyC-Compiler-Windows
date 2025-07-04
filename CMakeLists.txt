cmake_minimum_required(VERSION 3.15)
project(HolyCCompiler)

# Windows-specific configurations
if(WIN32)
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_STANDARD_REQUIRED ON)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

    # Use MSVC or MinGW
    if(MSVC)
        add_compile_options(/W4 /WX)
    else()
        add_compile_options(-Wall -Wextra -Werror)
    endif()
endif()

# Source files
file(GLOB_RECURSE SOURCES "src/*.c")

# Main executable
add_executable(hcc ${SOURCES})

# Installation
install(TARGETS hcc DESTINATION bin)
install(DIRECTORY src/holyc-lib/ DESTINATION include/holyc)