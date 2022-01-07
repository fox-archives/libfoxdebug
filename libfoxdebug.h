#if __cplusplus
  #error "Fam, C++ isn't supported"
#endif

#if _WIN32
  #warn "Stop using Windows 😡"
#endif

#if _MSC_VER
  #warn "Stop using MSVC 😡"
#endif

/* _Generic introduced in C11 */
#if __STDC_VERSION__ >= 201112L
enum FOX_TYPE {
  /* boolean type */
  FOX_TYPE_BOOL,
  /* character type */
  FOX_TYPE_CHAR,
  FOX_TYPE_SIGNED_CHAR,
  FOX_TYPE_UNSIGNED_CHAR,
  /* integer type */
  FOX_TYPE_SHORT_INT,
  FOX_TYPE_UNSIGNED_SHORT_INT,
  FOX_TYPE_INT,
  FOX_TYPE_UNSIGNED_INT,
  FOX_TYPE_LONG_INT,
  FOX_TYPE_UNSIGNED_LONG_INT,
  FOX_TYPE_LONG_LONG_INT,
  FOX_TYPE_UNSIGNED_LONG_LONG_INT,
  /* real floating types */
  FOX_TYPE_FLOAT,
  FOX_TYPE_DOUBLE,
  FOX_TYPE_LONG_DOUBLE,
#ifdef __STDC_IEC_60559_DFP__
  FOX_TYPE_DECIMAL32,
  FOX_TYPE_DECIMAL64,
  FOX_TYPE_DECIMAL128,
#endif
  /* complex floating types */
  FOX_TYPE_FLOAT_COMPLEX,
  FOX_TYPE_DOUBLE_COMPLEX,
  FOX_TYPE_LONG_DOUBLE_COMPLEX,
  /* imaginary floating types */
  FOX_TYPE_FLOAT_IMAGINARY,
  FOX_TYPE_DOUBLE_IMAGINARY,
  FOX_TYPE_LONG_DOUBLE_IMAGINARY,
  /* default */
  FOX_TYPE_DEFAULT,
};

#ifdef __STDC_IEC_60559_DFP__
  #define FOX_INTERNAL_DECIMAL \
    _Decimal32: FOX_TYPE_DECIMAL32, \
    _Decimal64: FOX_TYPE_DECIMAL64, \
    _Decimal128: FOX_TYPE_DECIMAL128,
#else
  #define FOX_INTERNAL_DECIMAL
#endif
#define fox_typename_get(controlling_expression) \
_Generic( \
  controlling_expression, \
  /* boolean type */ \
  _Bool: FOX_TYPE_BOOL, \
  /* character types */ \
  char: FOX_TYPE_CHAR, \
  signed char: FOX_TYPE_SIGNED_CHAR, \
  unsigned char: FOX_TYPE_UNSIGNED_CHAR, \
  /* integer types */ \
  short int: FOX_TYPE_SHORT_INT, \
  unsigned short int: FOX_TYPE_UNSIGNED_SHORT_INT, \
  int: FOX_TYPE_INT, \
  unsigned int: FOX_TYPE_UNSIGNED_INT, \
  long int: FOX_TYPE_LONG_INT, \
  unsigned long int: FOX_TYPE_UNSIGNED_LONG_INT, \
  long long int: FOX_TYPE_LONG_LONG_INT, \
  unsigned long long int: FOX_TYPE_UNSIGNED_LONG_LONG_INT, \
  /* real floating types */ \
  float: FOX_TYPE_FLOAT, \
  double: FOX_TYPE_DOUBLE, \
  long double: FOX_TYPE_LONG_DOUBLE, \
  /* FOX_INTERNAL_DECIMAL */ \
  /* complex floating types */ \
  float _Complex: FOX_TYPE_FLOAT_COMPLEX, \
  double _Complex: FOX_TYPE_DOUBLE_COMPLEX, \
  long double _Complex: FOX_TYPE_LONG_DOUBLE_COMPLEX, \
  /* imaginary floating types */ \
  /* float _Imaginary: FOX_TYPE_FLOAT_IMAGINARY, */ \
  /* double _Imaginary: FOX_TYPE_DOUBLE_IMAGINARY, */ \
  /* long double _Imaginary: FOX_TYPE_LONG_DOUBLE_IMAGINARY, */ \
  /* default */ \
  default: FOX_TYPE_DEFAULT \
)
#undef FOX_INTERNAL_DECIMAL

#define fox_typename_get_str(controlling_expression) \
  ffox_typename_get_str(fox_typename_get(controlling_expression))

char* ffox_typename_get_str(enum FOX_TYPE type_number) {
  switch (type_number) {
  /* boolean type */
  case FOX_TYPE_BOOL:
    return "bool";
  /* character types */
  case FOX_TYPE_CHAR:
    return "char";
  case FOX_TYPE_SIGNED_CHAR:
    return "signed char";
  case FOX_TYPE_UNSIGNED_CHAR:
    return "unsigned char";
  /* integer types */
  case FOX_TYPE_SHORT_INT:
    return "short int";
  case FOX_TYPE_UNSIGNED_SHORT_INT:
    return "unsigned short int";
  case FOX_TYPE_INT:
    return "int";
  case FOX_TYPE_UNSIGNED_INT:
    return "unsigned int";
  case FOX_TYPE_LONG_INT:
    return "long int";
  case FOX_TYPE_UNSIGNED_LONG_INT:
    return "unsigned long int";
  case FOX_TYPE_LONG_LONG_INT:
    return "long long int";
  case FOX_TYPE_UNSIGNED_LONG_LONG_INT:
    return "unsigned long long int";
  /* real floating types */
  case FOX_TYPE_FLOAT:
    return "float";
  case FOX_TYPE_DOUBLE:
    return "double";
  case FOX_TYPE_LONG_DOUBLE:
    return "long double";
#ifdef __STDC_IEC_60559_DFP__
  case FOX_TYPE_DECIMAL32:
    return "decimal32";
  case FOX_TYPE_DECIMAL64:
    return "decimal64";
  case FOX_TYPE_DECIMAL128:
    return "decimal128";
#endif
  /* complex floating types */
  case FOX_TYPE_FLOAT_COMPLEX:
    return "float complex";
  case FOX_TYPE_DOUBLE_COMPLEX:
    return "double complex";
  case FOX_TYPE_LONG_DOUBLE_COMPLEX:
    return "long double complex";
  /* imaginary floating types */
  case FOX_TYPE_FLOAT_IMAGINARY:
    return "float imaginary";
  case FOX_TYPE_DOUBLE_IMAGINARY:
    return "double imaginary";
  case FOX_TYPE_LONG_DOUBLE_IMAGINARY:
    return "long double imaginary";
  /* default */
  default:
    return "unknown";
  }
}

#define fox_typename_print(controlling_expression) \
  ffox_typename_print( \
    fox_typename_get(controlling_expression), \
    #controlling_expression, \
    &(controlling_expression) \
  )

void ffox_typename_print(enum FOX_TYPE type_number, char *variable_name, void *variable) {
  switch (type_number) {
  /* boolean type */
  case FOX_TYPE_BOOL:
    printf("%s (bool): %s\n", variable_name, *(_Bool*)variable ? "true" : "false");
    break;
  /* character types */
  case FOX_TYPE_CHAR:
    printf("Value of '%s' (char): %c\n", variable_name, *(char*)variable);
    break;
  case FOX_TYPE_SIGNED_CHAR:
    printf("Value of '%s' (signed char): %c\n", variable_name, *(signed char*)variable);
    break;
  case FOX_TYPE_UNSIGNED_CHAR:
    printf("Value of '%s' (unsigned char): %u\n", variable_name, *(unsigned char*)variable);
    break;
  /* integer types */
  case FOX_TYPE_SHORT_INT:
    printf("Value of '%s' (short int): %hd\n", variable_name, *(short int*)variable);
    break;
  case FOX_TYPE_UNSIGNED_SHORT_INT:
    printf("Value of '%s' (unsigned short int): %hu\n", variable_name, *(unsigned short int*)variable);
    break;
  case FOX_TYPE_INT:
    printf("Value of '%s' (int): %d\n", variable_name, *(int*)variable);
    break;
  case FOX_TYPE_UNSIGNED_INT:
    printf("Value of '%s' (unsigned int): %u\n", variable_name, *(unsigned int*)variable);
    break;
  case FOX_TYPE_LONG_INT:
    printf("Value of '%s' (long int): %ld\n", variable_name, *(long int*)variable);
    break;
  case FOX_TYPE_UNSIGNED_LONG_INT:
    printf("Value of '%s' (unsigned long int): %lu\n", variable_name, *(unsigned long int*)variable);
    break;
  case FOX_TYPE_LONG_LONG_INT:
    printf("Value of '%s' (long long int): %lld\n", variable_name, *(long long int*)variable);
    break;
  case FOX_TYPE_UNSIGNED_LONG_LONG_INT:
    printf("Value of '%s' (unsigned long long int): %llu\n", variable_name, *(unsigned long long int*)variable);
    break;
  /* real floating types */
  case FOX_TYPE_FLOAT:
    printf("Value of '%s' (float): %f\n", variable_name, *(float*)variable);
    break;
  case FOX_TYPE_DOUBLE:
    printf("Value of '%s' (double): %f\n", variable_name, *(double*)variable);
    break;
  case FOX_TYPE_LONG_DOUBLE:
    printf("Value of '%s' (long double): %Lf\n", variable_name, *(long double*)variable);
    break;
#ifdef __STDC_IEC_60559_DFP__
  case FOX_TYPE_DECIMAL32:
    printf("unsupported\n");
    break;
  case FOX_TYPE_DECIMAL64:
    printf("unsupported\n");
    break;
  case FOX_TYPE_DECIMAL128:
    printf("unsupported\n");
    break;
#endif
  /* complex floating types */
  case FOX_TYPE_FLOAT_COMPLEX:
    printf("unsupported\n");
    break;
  case FOX_TYPE_DOUBLE_COMPLEX:
    printf("unsupported\n");
    break;
  case FOX_TYPE_LONG_DOUBLE_COMPLEX:
    printf("unsupported\n");
    break;
  /* imaginary floating types */
  case FOX_TYPE_FLOAT_IMAGINARY:
    printf("unsupported\n");
    break;
  case FOX_TYPE_DOUBLE_IMAGINARY:
    printf("unsupported\n");
    break;
  case FOX_TYPE_LONG_DOUBLE_IMAGINARY:
    printf("unsupported\n");
    break;
  /* default */
  default:
    printf("unknown: %p\n", variable);
  }
}
#endif
