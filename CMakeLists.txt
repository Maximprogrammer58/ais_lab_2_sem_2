cmake_minimum_required(VERSION 3.11)

project(HashTable CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")   
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_library(HashTable SHARED
    "include/HashTable.h"
    "src/HashTable.cc"
    "include/Random.h"
    "src/Random.cc"
    "include/Hash.h"
    "src/Hash.cc"
    "include/Compare_hash.h"
    "src/Compare_hash.cc"
    "include/Equal.h"
    "src/Equal.cc"
)
target_include_directories(HashTable PUBLIC "include")

add_executable(main "main.cc")
target_link_libraries(main HashTable)