cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME "Sample")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(numbers_counter)

message("NumbersCounterLib_LIB = ${NumbersCounterLib_LIB}")
message("NumbersCounterLib_INCLUDE_DIRS = ${NumbersCounterLib_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${NumbersCounterLib_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC ${NumbersCounterLib_INCLUDE_DIRS})
