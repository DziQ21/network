cmake_minimum_required(VERSION 3.17)
project(siec)

set(CMAKE_CXX_STANDARD 14)


add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion -Wunused-variable)
add_executable(siec main.cpp Queue.cpp Queue.hpp Package.cpp Package.hpp storage_types.hpp storage_types.cpp
        types.hpp)