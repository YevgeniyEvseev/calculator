// #include "stack.h"

#include "../define.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
  stack_t* next;
  calc_t* data;
} stack_t;

stack_t* init() { return malloc(sizeof(stack_t)); }

void push(stack_t** root, calc_t* value) {
  stack_t* tmp = malloc(sizeof(stack_t));
  calc_t* val_aloc = malloc(sizeof(calc_t));
  val_aloc->oper = value->oper;
  val_aloc->type = value->type;
  val_aloc->value = value->value;
  tmp->data = val_aloc;
  tmp->next = *root;
  *root = tmp;
}
calc_t* pop(stack_t** root) {
  if (*root == NULL) return NULL;
  int res = (*root)->data;
  stack_t* tmp = (*root)->next;
  free(*root);
  *root = tmp;
  return res;
}

void ctor(stack_t* root) { root->next = NULL; }

calc_t* get_data_root(stack_t* root) { return root->data; }