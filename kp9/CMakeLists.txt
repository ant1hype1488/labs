cmake_minimum_required(VERSION 3.21)
project(kp9 C)

set(CMAKE_C_STANDARD 99)

add_executable(kp9 main.c funcs.h funcs.c)
