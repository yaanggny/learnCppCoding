project(complex_test)

message(STATUS "test: CMAKE_INSTALL_PREFIX= ${CMAKE_INSTALL_PREFIX}")

set(inc_dir
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib/inc    
)
include_directories(${inc_dir})

aux_source_directory(. SRCS)
add_executable(${PROJECT_NAME} ${SRCS})

# link_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../install/Windows/bin")

target_link_libraries(${PROJECT_NAME} complex_math)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)