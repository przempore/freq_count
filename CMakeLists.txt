project(freq_analizer)
cmake_minimum_required(VERSION 2.8.0)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

enable_testing()

add_subdirectory(main)
add_subdirectory(freq_count)
add_subdirectory(test)
