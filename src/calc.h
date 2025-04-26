#ifndef CALC_H
#define CALC_H

struct stack_t;
struct calc_t;

double string_to_double(char **c);
int string_to_func(char **s);
int parser(char **str, struct calc_t **array);
void add_calc_t(struct calc_t **data, int type, void *value);
void calculate(struct stack_t **digit, struct stack_t **oper);
double get_digit(struct stack_t **digit);
int get_operator(struct stack_t **oper);
double process_calc(char *expr);
#endif