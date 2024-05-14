cmake_minimum_required(VERSION 3.21)
project(main_c C)

set(CMAKE_C_STANDARD 99)

add_executable(main_c main.c matrix.c matrix.h)
