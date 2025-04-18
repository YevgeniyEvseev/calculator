#ifndef CALC_H
#define CALC_H

struct Stack_t;
struct calc_t;

double string_to_double(char **c);
void parser(char *str, struct calc_t *array);
#endif