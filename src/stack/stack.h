#ifndef STACK_H
#define STACK_H

#include "../define.h"

struct stack_t;

struct stack_t* init();
void ctor(struct stack_t* root);
void push(struct stack_t** root, calc_t* data);
calc_t* pop(struct stack_t** root);
calc_t* get_data_root(struct stack_t* root);

#endif