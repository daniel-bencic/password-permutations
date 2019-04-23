cmake_minimum_required(VERSION 3.9)
project(password-permutations)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
add_executable(password-permutations ${SOURCES})
