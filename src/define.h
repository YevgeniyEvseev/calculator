#ifndef DEFINE_H
#define DEFINE_H

#define CRITICAL 1
#define WARNING 0
#define OK 1
#define FAIL 0
#define TRUE 1
#define FALSE 0
#define MIN_ARRAY 8
#define COUNT_FUNC 6

enum { OPERATOR = 887, DIGIT = 888 };

enum { BRACKET_OPEN = 1, PLUS, MINUS, MUL, DIV, FUNC, BRACKET_CLOSE = 20 };
enum { SIN = 6, COS, TAN, SQRT, LN, POW };

#define ERR_1(NAME_ERROR) printf("%s %d %s", __FILE__, __LINE__, NAME_ERROR);

#define ERR_2(NAME_ERROR, type_error)                   \
  do {                                                  \
    printf("%s %d %s", __FILE__, __LINE__, NAME_ERROR); \
    if (type_error) {                                   \
      printf("");                                       \
      abort();                                          \
    }                                                   \
  } while (0)

#define ERR_VAR(A1, A2, A3, ...) A3
#define ER_MACRO_CHOOSER(...) ERR_VAR(__VA_ARGS__, ERR_2, ERR_1)
#define ERROR(...) ER_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

typedef struct {
  int type;
  union {
    int oper;
    double value;
  };
} calc_t;

#endif