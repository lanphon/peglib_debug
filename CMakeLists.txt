cmake_minimum_required(VERSION 3.12)
project(puasmlang)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_definitions(-ggdb)

set(BIN_PATH ${CMAKE_SOURCE_DIR}/bin64)

include_directories(include)
aux_source_directory(source SRC)
list(REMOVE_ITEM SRC source/testlang.cpp)

set(TESTL testl)

add_library(${TESTL} ${SRC})
set_target_properties(${TESTL} PROPERTIES POSITION_INDEPENDENT_CODE ON)

set(LIB_TARGET testlang)
add_library(${LIB_TARGET} SHARED source/testlang.cpp)
target_include_directories(${LIB_TARGET} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app)
target_link_libraries(${LIB_TARGET} PRIVATE ${TESTL})
if (MSVC)
    set_target_properties(${LIB_TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_PATH}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_PATH}
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${BIN_PATH}
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${BIN_PATH}
    VS_DEBUGGER_WORKING_DIRECTORY ${BIN_PATH}
    )
else()
    set_target_properties(${LIB_TARGET} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${BIN_PATH}
    )
endif()

add_subdirectory(test)
