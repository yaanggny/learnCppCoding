cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set the project name
project(helloCMake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/math)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/math SRC_ext)

set(CMAKE_DEBUG_POSTFIX d)
add_library(mmath SHARED ${SRC_ext})
add_library(mmaths STATIC ${SRC_ext})

message(STATUS "SRC_ext= ${SRC_ext}")

# add the executable
add_executable(${PROJECT_NAME} main.cpp ${SRC_ext})