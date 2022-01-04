cmake_minimum_required(VERSION 3.17)
project(siec)

set(CMAKE_CXX_STANDARD 14)


add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion -Wunused-variable)

include_directories(include)

set(SOURCE_FILES
        src/storage_types.cpp
        src/package.cpp
        src/Queue.cpp
        src/factory.cpp
        src/helpers.cpp
        src/nodes.cpp)

add_executable(siec ${SOURCE_FILES} main.cpp)

#Queue.cpp Queue.hpp Package.cpp Package.hpp storage_types.hpp storage_types.cpp
#        types.hpp)