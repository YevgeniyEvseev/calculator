#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "define.h"

int main() {
  char d[10] = "3.234+";
  char *c = d;
  double n = string_to_double(&c);
  printf("%lf == %c", n, *c);
  // ERROR("dddd", 1);
}