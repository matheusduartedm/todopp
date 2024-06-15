cmake_minimum_required(VERSION 3.28)
project(todopp)

set(CMAKE_CXX_STANDARD 26)

file(GLOB SOURCES "src/*.cpp" "src/*.h")

add_executable(todopp ${SOURCES})
