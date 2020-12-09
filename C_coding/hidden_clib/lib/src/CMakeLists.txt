project(complex_math)

aux_source_directory(. SRCS)
message(STATUS "SRCS=${SRCS}")

set(inc_dir
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc     
    ${CMAKE_CURRENT_SOURCE_DIR}    
)
include_directories(${inc_dir})

add_library(${PROJECT_NAME} STATIC ${SRCS})


# install
if(WIN32)
    install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
    # install(TARGETS ${PROJECT_NAME}S DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/static)
elseif(UNIX)
    install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}S
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/static)
endif()

install(DIRECTORY ../inc/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include
    FILES_MATCHING PATTERN "*.h")
