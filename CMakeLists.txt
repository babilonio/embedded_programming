cmake_minimum_required(VERSION 3.10)
project(EmbeddedProgramming VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

ENABLE_TESTING()

add_subdirectory (src)
add_subdirectory (tst)
add_subdirectory(lib/googletest)