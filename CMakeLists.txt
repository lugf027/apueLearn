cmake_minimum_required(VERSION 3.17)
project(unixLearn C)

set(CMAKE_C_STANDARD 11)

add_executable(unixLearn main.c)
add_executable(1_3_ls src/1_3_ls/ls.c)
add_executable(1_4_cp src/1_4_cp/cp.c)
