#ifndef STACK_H
#define STACK_H

struct stack_t;
struct calc_t;

struct stack_t* init();
void push(struct stack_t* root, struct calc_t* data);
struct calc_t* pop(struct stack_t* root);

#endif