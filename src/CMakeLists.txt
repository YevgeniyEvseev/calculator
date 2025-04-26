cmake_minimum_required(VERSION 3.2)

project(calculator)

add_executable(calc_debug 
main.c
calc.c
stack/stack.c 
)

target_link_libraries(calc_debug PRIVATE m )