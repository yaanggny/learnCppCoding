cmake_minimum_required(VERSION 2.8)

project(complex)

if(WIN32)
    set(InstallDir ${CMAKE_BINARY_DIR}/../install/Windows)
elseif(UNIX)
    set(InstallDir ${CMAKE_BINARY_DIR}/../install/Linux)
elseif(ANDROID)
    set(InstallDir ${CMAKE_BINARY_DIR}/../install/android)
else()
    message(STATUS "unkown platform" FETAL_ERROR)
endif()

set(CMAKE_INSTALL_PREFIX ${InstallDir})
message(STATUS "CMAKE_INSTALL_PREFIX= ${CMAKE_INSTALL_PREFIX}")

add_subdirectory(lib)
add_subdirectory(test)

