# http://www.kaizou.org/2014/11/gtest-cmake/

# cmake_minimum_required(VERSION 2.8.0)
# project(unitTests)

# set(CMAKE_CXX_STANDARD 17)

# include(DownloadProject.cmake)
# download_project(PROJ                googletest
#                  GIT_REPOSITORY      https://github.com/google/googletest.git
#                  GIT_TAG             master
#                  ${UPDATE_DISCONNECTED_IF_AVAILABLE}
# )

# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# if (CMAKE_VERSION VERSION_LESS 2.8.11)
#     include_directories("${gtest_SOURCE_DIR}/include"
#                         "${gmock_SOURCE_DIR}/include")
# endif()

# file(GLOB test_SRC
#         src/*.cpp)

# add_library(${PROJECT_NAME}_test OBJECT ${test_SRC})
# add_executable(runUnitTests $<TARGET_OBJECTS:${PROJECT_NAME}_test>)

# target_link_libraries(runUnitTests gtest gmock_main test)
# # add_test(runUnitTests runUnitTests)
# add_test(NAME runUnitTests_test COMMAND runUnitTests)

# ======================================================================================
find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

add_subdirectory(src)