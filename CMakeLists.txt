# mimimum required version 3.15: policy CMP0092
# mimimum required version 3.12: target_compile_features C++ 20
# mimimum required version 3.8:  target_compile_features C++ 17
cmake_minimum_required(VERSION 3.15)

# policy CMP0092 MSVC COMPILE FLAGS -- no warings by default
cmake_policy(SET CMP0092 NEW)

# Project name
project(dte3603_2021_candidate_id VERSION 0.1 LANGUAGES CXX)

# Ease of setup protection on Wintendo OSes
if(MSVC AND NOT VCPKG_TOOLCHAIN)
  message(FATAL_ERROR
    "Enable VCPKG toolchain on MSVC platform\n"
    "  Star over; CMAKE_TOOLCHAIN_FILE definition missing!\n"
    "  i.e.: cmake -DCMAKE_TOOLCHAIN_FILE=<path_to>\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake <path_to>\\source\\"
    )
endif()

## Global compiler spesific compile options
SET(CLANG_COMPILE_OPTIONS
    # REQUIRED ON
    -Weverything -pedantic -Werror
    -Wno-c++98-compat -Wno-c++98-compat-pedantic
    # REQUIRED ON

    # Turn off warning for undocumented code fragments
    -Wno-documentation
  )

SET(GCC_COMPILE_OPTIONS
    # REQUIRED ON
    -pedantic -Wall -Werror
    # REQUIRED ON
  )

SET(MSVC_COMPILE_OPTIONS
    # REQUIRED ON

    /W4 /permissive-
    # REQUIRED ON
  )

# Find boost
find_package(Boost 1.72 REQUIRED COMPONENTS graph)
target_compile_options( Boost::graph
    INTERFACE $<$<CXX_COMPILER_ID:Clang>: -w >
    INTERFACE $<$<CXX_COMPILER_ID:GNU>: -w >
#    INTERFACE $<$<CXX_COMPILER_ID:MSVC>: /w > # Turn on if MSVC complains
  )
target_compile_definitions(Boost::graph
    INTERFACE $<$<CXX_COMPILER_ID:GNU>: BOOST_ALLOW_DEPRECATED_HEADERS > # Boost post c++17 compile bug
  )

# Include shared predfined inline helper sources
add_subdirectory(predef_shared)

# Include internal library subfolders
add_subdirectory(day1_2_sort)
add_subdirectory(day3_string_match)
add_subdirectory(day4_graph_traversal)
add_subdirectory(day5_graph_path_finding)


###########################################
# Qt creator dummy target
option(DUMMY_TARGET "Dummy target..." TRUE)
if(DUMMY_TARGET)
  add_custom_target(${PROJECT_NAME}_DUMMY)
endif(DUMMY_TARGET)


