aux_source_directory(./ SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-graphics sfml-window sfml-audio)
target_include_directories(${PROJECT_NAME} PUBLIC "../third_party/SFML/include")
add_compile_definitions(PROJECT_NAME="${PROJECT_NAME}")