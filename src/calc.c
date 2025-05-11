#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "stack/stack.h"

const char *func_arithm[COUNT_FUNC] = {"sin", "cos", "tan", "sqrt",
                                       "ln",  "log", "mod"};

double get_digit(struct stack_t **digit) {
  double res;
  if (*digit == NULL) ERROR("stack is empty", CRITICAL);
  calc_t *tmp = pop(digit);
  res = tmp->value;
  free(tmp);
  return res;
}

int get_operator(struct stack_t **oper) {
  int res;
  calc_t *tmp = pop(oper);
  res = tmp->oper;
  free(tmp);
  return res;
}

void add_calc_t(calc_t **data, int type, void *value) {
  *data = malloc(sizeof(calc_t));
  switch (type) {
    case DIGIT:
      double res_d = *(double *)value;
      (*data)->type = DIGIT;
      (*data)->value = res_d;
      break;
    case OPERATOR:
      int res = *(int *)value;
      (*data)->oper = res;
      (*data)->type = OPERATOR;
      break;
    default:
      ERROR("type is uncorrect", CRITICAL);
      break;
  }
}

int is_alfavit(char *s) {
  return ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z'));
}

// return number function or (-1) if not
int string_to_func(char **s) {
  int res = -1;
  int find_arr = -1;
  if (!is_alfavit(*s)) return res;
  for (int i = 0; i < COUNT_FUNC; i++) {
    char *c = *s;
    int count = 0;
    while (TRUE) {
      if (*c != *(func_arithm[i] + count)) break;
      c++;
      count++;
      if (*(func_arithm[i] + count) == '\0') {
        *s = c;
        return i;
      }
    }
  }
  return res;
}

void calculate(struct stack_t **digit, struct stack_t **oper) {
  int operator = get_operator(oper);
  if (operator == BRACKET_OPEN || operator == BRACKET_CLOSE) return;
  double n1 = get_digit(digit);
  switch (operator) {
    case PLUS:
      n1 += get_digit(digit);
      break;
    case MINUS:
      n1 = get_digit(digit) - n1;
      break;
    case MUL:
      n1 *= get_digit(digit);
      break;
    case DIV:
      n1 = get_digit(digit) / n1;
      break;
    case SIN:
      n1 = sin(n1);
      break;
    case COS:
      n1 = cos(n1);
      break;
    case TAN:
      n1 = tan(n1);
      break;
    case LN:
      n1 = log(n1);
      break;
    case LOG:
      n1 = log10(n1);
      break;
    case SQRT:
      n1 = pow(n1, 0.5);
      break;
    case POW:
      n1 = pow(get_digit(digit), n1);
      break;
    case MOD:
      n1 = fmod(get_digit(digit), n1);
      break;
    default:
      ERROR("operator is uncorrect", CRITICAL);
      break;
  }
  calc_t *tmp;
  add_calc_t(&tmp, DIGIT, &n1);
  push(digit, tmp);
  // return n1;
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
  // printf("res = %lf\n", res);
  *s = c;
  return res;
}

int string_to_oper(char **s) {
  int res;
  char *c = *s;
  switch (*c) {
    case '+':
      res = PLUS;
      break;
    case '-':
      res = MINUS;
      break;
    case '*':
      res = MUL;
      break;
    case '/':
      res = DIV;
      break;
    case '^':
      res = POW;
      break;
    case '(':
      res = BRACKET_OPEN;
      break;
    case ')':
      res = BRACKET_CLOSE;
      break;
    default:
      break;
  }
  c++;
  *s = c;
  return res;
}

int parser(char **str, calc_t **array) {
  // int check_bracket = 0;
  int oper;
  char *tmp = *str;
  switch (**str) {
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
      add_calc_t(array, DIGIT, &n);
      break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '^':
      oper = string_to_oper(str);
      add_calc_t(array, OPERATOR, &oper);
      break;
    case '=':
      return FALSE;
      break;

    default:
      if ((oper = string_to_func(str)) < 0) {
        ERROR("Operator or function is unknown", ALARM);
        return ERROR_ALARM;
      }
      oper += FUNC;
      add_calc_t(array, OPERATOR, &oper);
      break;
  }

  return TRUE;
}

double process_calc(char *expr) {
  calc_t *tmp;
  double res;
  struct stack_t *digit = NULL;
  struct stack_t *oper = NULL;
  while (parser(&expr, &tmp)) {
    if (tmp->type == DIGIT) {
      push(&digit, tmp);
    }
    if (tmp->type == OPERATOR) {
      if (tmp->oper == MINUS && (digit == NULL || *(expr - 2) == '(')) {
        double d = 0;
        calc_t *null_d;
        add_calc_t(&null_d, DIGIT, &d);
        push(&digit, null_d);
      }
      if (oper != NULL && tmp->oper != BRACKET_OPEN) {
        calc_t *root = get_data_root(oper);
        if (root->oper == BRACKET_CLOSE) {
          do {
            calculate(&digit, &oper);
            root = get_data_root(oper);
          } while (root->oper != BRACKET_OPEN);
        }
        while (oper != NULL && tmp->oper <= root->oper) {
          calculate(&digit, &oper);
          if (oper != NULL) root = get_data_root(oper);
        }
      }
      push(&oper, tmp);
    }
  }
  while (oper != NULL) {
    calculate(&digit, &oper);
  }
  return get_digit(&digit);
}
