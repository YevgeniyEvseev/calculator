#ifndef STACK_H
#define STACK_H

struct stack_t;

struct stack_t* init();
void ctor(struct stack_t* root, int data);
void push(struct stack_t** root, int data);
int pop(struct stack_t** root);
int get_data_root(struct stack_t* root);

#endif