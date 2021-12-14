cmake_minimum_required(VERSION 3.17)
project(siec)

set(CMAKE_CXX_STANDARD 14)


add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion -Wunused-variable)
add_executable(siec main.cpp Queue.cpp Queue.hpp Product.cpp Product.hpp)