cmake_minimum_required(VERSION 3.20)
project(kv_server CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(kv_server src/main.cpp)

enable_testing()
add_executable(kv_tests tests/smoke_test.cpp)
target_link_libraries(kv_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(kv_tests)