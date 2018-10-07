cmake_minimum_required(VERSION 2.8)

project(computorV1)
set (CMAKE_CXX_STANDARD 11)
set(SOURCE main.cpp validation.cpp validation.h calculation.cpp calculation.h)
add_executable(${PROJECT_NAME} ${SOURCE})
