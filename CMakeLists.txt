cmake_minimum_required(VERSION 3.9)
project(password-permutations)

include_directories(include)

add_executable(password-permutations src/main.cpp
        src/table.cpp)
