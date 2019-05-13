set(main_SRC
    main.cpp
)

set(CXX_STANDARD 17)

add_executable(freq_analizer_app
    ${main_SRC}
)

target_link_libraries(freq_analizer_app
    freq_count
)

install(TARGETS freq_analizer_app DESTINATION bin)
