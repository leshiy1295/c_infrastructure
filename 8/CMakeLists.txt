cmake_minimum_required(VERSION 3.0.0)
project(printer)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")

add_subdirectory(print)

message("PRINTER_LIB_INCLUDE_DIRS = ${PRINTER_LIB_INCLUDE_DIRS}")
message("PRINTER_LIB_LIBRARIES = ${PRINTER_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${PRINTER_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PRINTER_LIB_LIBRARIES})
