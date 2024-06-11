cmake_minimum_required(VERSION 3.10)

project(EldenRingModsGui VERSION 1.0.0 LANGUAGES CXX)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "src/*.h" "src/*.hpp")

add_library(ModGui SHARED ${SOURCES}
        src/Config/Config.cpp
        src/Config/Config.h
        src/Console/Console.cpp
        src/Console/Console.h)

set_target_properties(ModGui PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_include_directories(ModGui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(ModGui PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

