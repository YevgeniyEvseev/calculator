#include "stack.h"

#include "../define.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct {
  stack_t* next;
  int index_array;
} stack_t;

stack_t* init() { return malloc(sizeof(stack_t)); }

void push(stack_t** root, int index) {
  stack_t* tmp = malloc(sizeof(stack_t));
  tmp->index_array = index;
  tmp->next = *root;
  *root = tmp;
}
int pop(stack_t** root) {
  if (*root == NULL) return NULL;
  int res = (*root)->index_array;
  stack_t* tmp = (*root)->next;
  free(*root);
  *root = tmp;
  return res;
}

void ctor(stack_t* root, int index) {
  root->next = NULL;
  root->index_array = index;
}

int get_data_root(stack_t* root) { return root->index_array; }