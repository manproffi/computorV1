cmake_minimum_required(VERSION 2.8)

project(computorV1)
set (CMAKE_CXX_STANDARD 11)
set(SOURCE main.cpp lexer.cpp lexer.h validation.cpp validation.h)
add_executable(${PROJECT_NAME} ${SOURCE})
