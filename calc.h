#ifndef CALC_H
#define CALC_H

enum{BRACKET_OPEN=1, PLUS, MINUS, MUL, DIV, BRACKET_CLOSE};

struct Stack_t;

double float_to_int(char *c);
void parser(char *str, Stack_t *digit, Stack_t *oper);
#endif