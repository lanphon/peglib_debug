#/* vim: set filetype=cmake : */ ~
get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)
aux_source_directory(. SAMPLE_SRC)

add_executable(${TARGET} ${SAMPLE_SRC})
target_link_libraries(${TARGET} PUBLIC Threads::Threads ${TESTL} ${LIB_TARGET})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # only gcc should be linked against to c++fs
    # MSVC/Clang do not need it
    target_link_libraries(${TARGET} PUBLIC stdc++fs)
endif()

if(MSVC)
    set_target_properties(${TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_PATH}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_PATH}
        VS_DEBUGGER_WORKING_DIRECTORY ${BIN_PATH}
        )
else()
    set_target_properties(${TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH}
        )
    target_link_libraries(${TARGET} PUBLIC dl Threads::Threads)
endif()
