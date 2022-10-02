cmake_minimum_required(VERSION 3.14)
project(numbers_counter_tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

include(GoogleTest)
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${NumbersCounterLib_LIB} GTest::gtest_main)
target_include_directories(${PROJECT_NAME} PUBLIC ${NumbersCounterLib_INCLUDE_DIRS})

gtest_discover_tests(${PROJECT_NAME})
