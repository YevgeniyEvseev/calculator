#ifndef CALC_H
#define CALC_H

struct stack_t;
struct calc_t;

double string_to_double(char **c);
int parser(char **str, struct calc_t *array);
void add_calc_t(struct calc_t *data, int type, void *value);
double calculate(struct stack_t **digit, struct stack_t **oper);
#endif