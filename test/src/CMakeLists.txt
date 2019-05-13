set(CXX_STANDARD 17)

file(GLOB SRC *.cpp)

add_executable(test_src ${SRC})

INCLUDE_DIRECTORIES(include)

target_link_libraries(test_src
    libgtest
    libgmock
    freq_count
)

install(TARGETS test_src DESTINATION bin)
