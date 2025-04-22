#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "define.h"

int main() {
  char d[20] = "(2-3.2*2)*4=";
  char *tmp_s = d;
  double p = process_calc(tmp_s);
  printf("%lf", p);

  // ERROR("dddd", 1);
}