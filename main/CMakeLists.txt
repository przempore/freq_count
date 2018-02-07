set(main_SRC
    main.cpp
)

add_executable(freq_analizer
    ${main_SRC}
)

target_link_libraries(freq_analizer
    freq_count
)

install(TARGETS freq_analizer DESTINATION bin)