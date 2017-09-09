cmake_minimum_required(VERSION 3.1)
project(osutils)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(src)



add_subdirectory(vendor/Catch)
include_directories(vendor/Catch/include)
include_directories(include)
enable_testing ()
add_subdirectory(test)

add_subdirectory(example)
