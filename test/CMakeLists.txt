# http://www.kaizou.org/2014/11/gtest-cmake/

cmake_minimum_required(VERSION 2.8.0)
project(unitTests)

set(CMAKE_CXX_STANDARD 17)

include(DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

file(GLOB test_SRC
        src/*.cpp)

# add_library(Deadstorm_obj OBJECT ${game_SRC})
add_library(${PROJECT_NAME}_test OBJECT ${test_SRC})
add_executable(runUnitTests ${test_SRC})

target_link_libraries(runUnitTests gtest gmock_main)
# # add_test(runUnitTests runUnitTests)
# add_test(NAME runUnitTests_test COMMAND runUnitTests)