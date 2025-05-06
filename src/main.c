#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "define.h"

int main() {
  char *tmp_s = "-10+(-3*2^4)=";
  double p = process_calc(tmp_s);

  printf("%lf", p);

  // ERROR("dddd", 1);
}