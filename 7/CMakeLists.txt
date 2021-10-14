cmake_minimum_required(VERSION 3.0.0)
project(printer VERSION 0.1.0)

file(GLOB SOURCES "*.c" "**/*.c")
file(GLOB INCLUDE_DIRS print)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

message("SOURCES = ${SOURCES}")
