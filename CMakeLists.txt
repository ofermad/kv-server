cmake_minimum_required(VERSION 3.20)
project(kv_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(kv_core src/storage.cpp)
target_include_directories(kv_core PUBLIC src)

add_executable(kv_server src/main.cpp)
target_link_libraries(kv_server PRIVATE kv_core)

include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(storage_test tests/storage_test.cpp tests/smoke_test.cpp)
target_link_libraries(storage_test PRIVATE kv_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(storage_test)