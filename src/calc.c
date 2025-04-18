#include <stdio.h>

#include "define.h"
#include "stack/stack.h"

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

void parser(char *str, calc_t *array) {
  int check_bracket = 0;
  int oper;
  double n;
  while (TRUE) {
    switch (*str++) {
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
        n = string_to_double(&str);

        break;

      default:
        break;
    }
  }
  if (check_bracket != 0) ERROR("open and close brackets is't equel", CRITICAL);
}