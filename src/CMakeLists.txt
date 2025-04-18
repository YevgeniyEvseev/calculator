cmake_minimum_required(VERSION 3.2)

project(calculator)

add_executable(calc_debug 
main.c
calc.c
stack/stack.c 
array/array.c
)