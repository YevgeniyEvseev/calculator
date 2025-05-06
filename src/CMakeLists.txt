cmake_minimum_required(VERSION 3.2)

project(calculator)

add_executable(calc
main.c
calc.c
stack/stack.c 
)

add_executable(check_calc 
test.c 
calc.c
stack/stack.c 
)

target_link_libraries(calc PRIVATE m )
target_link_libraries(check_calc PRIVATE m check subunit rt pthread )