cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall")

set(libfoo_SRCS
    foo.h
    foo.cpp
    ibar.h
)

file(GLOB freq_count_src
	"include/*.hpp",
	"source/*.cpp")


include_directories("include")

# Declare the library
add_library(freq_count STATIC
    ${freq_count_src}
)

target_include_directories(freq_count PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)