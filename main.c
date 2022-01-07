// #include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

#define __STDC_IEC_60559_DFP__

#include "libfox.h"


int main() {
  // _Decimal128 dec = 0.0F;
  double _Imaginary dec = 3*I;

  int result = fox_get_typename(dec);
  char* str = fox_get_typename_str(result);
  printf("your type is: '%s'\n", str);
}
