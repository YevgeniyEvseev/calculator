#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "stack/stack.h"

double process_calc(char *expr) {
  calc_t tmp;
  struct stack_t *digit = init();
  struct stack_t *oper = init();
  while (parser(&expr, &tmp)) {
    if (tmp.type == DIGIT) {
      push(&digit, &tmp);
    }
    if (tmp.type == OPERATOR) {
      calc_t *root = get_data_root(oper);
      if (tmp.oper < root->type) {
        calculate(&digit, &oper);
      }
      push(&oper, &tmp);
    }
  }
}

double calculate(struct stack_t **digit, struct stack_t **oper) {
  calc_t *tmp = pop(oper);
  int operator= tmp->oper;
  double n1, n2;
  switch (operator) {
    case PLUS:
      /* code */
      break;

    default:
      break;
  }
}

// return digit(0..9) or -1 if not digit
int its_digit(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  return -1;
}

double string_to_double(char **s) {
  char *c = *s;
  double res = 0;
  int n;
  while ((n = its_digit(*c)) != -1) {
    res = res * 10 + n;
    c++;
  }
  if (*c == '.') {
    c++;
    int ten = 10;
    while ((n = its_digit(*c)) != -1) {
      res += (double)n / ten;
      ten *= 10;
      c++;
    }
  }
  printf("res = %lf\n", res);
  *s = c;
  return res;
}

void add_calc_t(calc_t *data, int type, void *value) {
  if (type == DIGIT) {
    double res_d = *(double *)value;
    data->value = res_d;
  }
  if (type == OPERATOR) {
    int res = *(int *)value;
    data->oper = res;
  } else {
    ERROR("type is uncorrect", CRITICAL);
  }
}

int parser(char **str, calc_t *array) {
  // int check_bracket = 0;
  int oper;
  switch (**str++) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      double n = string_to_double(str);
      new_calc_t(array, DIGIT, &n);
    case '+':
      oper = PLUS;
    case '-':
      oper = MINUS;
    case '*':
      oper = MUL;
    case '/':
      oper = DIV;
      add_calc_t(array, OPERATOR, &oper);
      break;
    case '=':
      return FALSE;
      break;
      ;

    default:
      // if(func());
      // else ERROR("expresion is uncorrect",CRITICAL);
      break;
  }

  return TRUE;
}