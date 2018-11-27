cmake_minimum_required(VERSION 3.12)
project(hash_table)

set(CMAKE_CXX_STANDARD 11)

add_executable(hash_table main.cpp hash_quad.cpp hash_quad.h)