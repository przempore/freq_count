cmake_minimum_required(VERSION 2.8)

set(CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall")

file(GLOB freq_count_src
	"include/*.hpp",
	"source/*.cpp")

include_directories("include")

project(freq_count)
add_library(${PROJECT_NAME}_obj OBJECT ${freq_count_src})
add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:${PROJECT_NAME}_obj> main.cpp)
