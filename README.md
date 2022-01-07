# foxdebuglib

`foxdebuglib` (the name is likely to change) is a header-only C library that provides some useful debugging facilities

As of now, it's pretty much a meme library with a _really_ cool variable printer (see below)

## Usage

```c
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "libfoxdebug.h"

int main() {
  int n = 5;
  float j = 5.5F;
  long long int super_long = 44;

  fox_typename_print(n);
  fox_typename_print(j);
  fox_typename_print(super_long);
}
```

Output...

```txt
$ gcc -Wpedantic -Wextra main.c && ./a.out
Value of 'n' (int): 5
Value of 'j' (float): 5.500000
Value of 'super_long' (long long int): 44
```

It's implemented with C11's [_Generic](https://en.cppreference.com/w/c/language/generic) with a little bit of macro magic sprinkled in. Note that the parameter to `fox_typename_print` _must_ be at least an lvalue expression

## TODO

- Fix _Decimal32, _Decimal64, and _Decimal128
- Fix complex floating types (`_Complex`)
- Fix imaginary floating types (`_Imaginary`)
- `FOX_TYPE_CHAR` compiler dependent
- Show less macro errors if there is a non-foxdebug-lib error, if possible (validation)
