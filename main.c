#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "libfoxdebug.h"

int main() {
  bool var = true;
  int result = fox_typename_get(var);
  if (result == FOX_TYPE_BOOL) {
    printf("'Tis a bool!\n");
  }

  char* str = fox_typename_get_str(var);
  printf("Your type: '%s'\n", str);

  int n = 5;
  float j = 5.5F;
  long long int super_long = 44;
  fox_typename_print_str(n);
  fox_typename_print_str(j);
  fox_typename_print_str(super_long);
}
