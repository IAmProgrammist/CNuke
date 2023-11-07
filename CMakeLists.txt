cmake_minimum_required(VERSION 3.16)
project(discrete_math C)

set(CMAKE_C_STANDARD 23)

add_executable(ma src/main.c)
target_include_directories(ma PUBLIC include)