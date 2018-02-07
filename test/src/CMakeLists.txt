file(GLOB SRC *.cpp)

add_executable(test_src ${SRC})

target_link_libraries(test_src
    freq_count
    libgtest
    libgmock
)

install(TARGETS test_src DESTINATION bin)