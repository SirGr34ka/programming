cmake_minimum_required(VERSION 3.5)

project(lab6)

set(SOURCE_FILES main.cpp matrix.cpp max_pooling.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})