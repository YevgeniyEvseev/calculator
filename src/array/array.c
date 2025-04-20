#include <stdlib.h>
#include <string.h>

#include "../define.h"

typedef struct {
  calc_t *data;
  int size;
  int count;
} array_t;

array_t *init() { return malloc(sizeof(array_t)); }

void ctor_array_t(array_t *arr) {
  arr->size = MIN_ARRAY;
  arr->count = 0;
  arr->data = malloc(sizeof(calc_t) * arr->size);
  if (arr->data == NULL) ERROR("malloc is uncorrect", CRITICAL);
}

int is_full(array_t *arr) { return (arr->count == arr->size); }

int is_empty(array_t *arr) { return arr->count == 0; }

void resize(array_t *arr) {
  arr->size *= 2;
  calc_t *new = malloc(sizeof(calc_t) * arr->size);
  memcpy(new, arr->data, sizeof(calc_t) * arr->count);
  free(arr->data);
  arr->data = new;
}

void push(array_t *arr, int type, void *data) {
  if (is_full(arr)) resize(arr);
  arr->count++;
  (arr->data + arr->count)->type = type;
  if (type == DIGIT) {
    double res_d = *(double *)data;
    (arr->data + arr->count)->value = res_d;
  }
  if (type == OPERATOR) {
    int res = *(int *)data;
    (arr->data + arr->count)->oper = res;
  } else {
    ERROR("type is uncorrect", CRITICAL);
  }
}
