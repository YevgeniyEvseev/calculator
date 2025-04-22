// #include "stack.h"

#include "../define.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  struct Node* next;
  calc_t* data;
} stack_t;

stack_t* init() {
  stack_t* tmp = malloc(sizeof(stack_t));
  tmp->data = NULL;
  tmp->next = NULL;
}

void push(stack_t** root, calc_t* value) {
  stack_t* tmp = malloc(sizeof(stack_t));
  tmp->data = value;
  tmp->next = *root;
  *root = tmp;
}
calc_t* pop(stack_t** root) {
  stack_t* tmp = NULL;
  if (*root == NULL) return NULL;
  calc_t* res = (*root)->data;
  if ((*root)->next != NULL) tmp = (*root)->next;
  free(*root);
  *root = tmp;
  return res;
}

void ctor(stack_t* root) { root->next = NULL; }

calc_t* get_data_root(stack_t* root) { return root->data; }