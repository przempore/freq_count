cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall")

set(freq_count_src
    consts.hpp
    file_operator.hpp
    file_operator.cpp
    text_manipulator.hpp
    text_manipulator.cpp
    )


# Declare the library
add_library(freq_count STATIC
    ${freq_count_src}
)

target_include_directories(freq_count PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
