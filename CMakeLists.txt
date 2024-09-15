cmake_minimum_required(VERSION 3.10)

project(gobang VERSION 1.0)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/main
    ${CMAKE_CURRENT_SOURCE_DIR}/main/parser
    ${CMAKE_CURRENT_SOURCE_DIR}/main/chessboard
)

file(GLOB_RECURSE
	source_file_list
	${CMAKE_CURRENT_SOURCE_DIR}/main/*.c
	${CMAKE_CURRENT_SOURCE_DIR}/main/*.cpp
)

add_executable(gobang ${source_file_list})
