#define _GNU_SOURCE
#include <math.h>
#include <mpfr.h>
#include <stdio.h>
#include <stdlib.h>

#define FLOAT_PREC 24
#define FLOAT_EMIN -148
#define FLOAT_EMAX 128

#define DOUBLE_PREC 53
#define DOUBLE_EMIN -1073
#define DOUBLE_EMAX 1024

#define BINARY128_PREC 112

MPFR_DECL_INIT(mpfr_x, BINARY128_PREC);
MPFR_DECL_INIT(mpfr_y, BINARY128_PREC);

#define MPFR_SET_FLT(X)                                                        \
  _Generic((X), float                                                          \
           : mpfr_set_flt(mpfr_##X, X, MPFR_RNDN), double                      \
           : mpfr_set_d(mpfr_##X, X, MPFR_RNDN))

#define MPFR_GET_FLT(X)                                                        \
  _Generic((X), float                                                          \
           : mpfr_get_flt(mpfr_##X, MPFR_RNDN), double                         \
           : mpfr_get_d(mpfr_##X, MPFR_RNDN), float*                        \
           : mpfr_get_flt(mpfr_##X, MPFR_RNDN), double* \
           : mpfr_get_d(mpfr_##X, MPFR_RNDN))

#define DEFINE_1_WRAPPER(NAME, TYPE, FUNCTION)                                 \
  TYPE NAME(TYPE x) {                                                          \
    MPFR_SET_FLT(x);                                                           \
    mpfr_##FUNCTION(mpfr_x, mpfr_x, MPFR_RNDN);                                \
    typeof(x) ret = MPFR_GET_FLT(x);                                           \
    return ret;                                                                \
  }

#define DEFINE_1i_1_WRAPPER(NAME, TYPE, FUNCTION)                              \
  TYPE NAME(int n, TYPE x) {                                                   \
    MPFR_SET_FLT(x);                                                           \
    mpfr_##FUNCTION(mpfr_x, n, mpfr_x, MPFR_RNDN);                             \
    typeof(x) ret = MPFR_GET_FLT(x);                                           \
    return ret;                                                                \
  }

#define DEFINE_1_1p_WRAPPER(NAME, TYPE, FUNCTION)                              \
  TYPE NAME(TYPE x, int *s) {                                                  \
    MPFR_SET_FLT(x);                                                           \
    mpfr_##FUNCTION(mpfr_x, s, mpfr_x, MPFR_RNDN);                             \
    typeof(x) ret = MPFR_GET_FLT(x);                                           \
    return ret;                                                                \
  }

#define DEFINE_2_WRAPPER(NAME, TYPE, FUNCTION)                                 \
  TYPE NAME(TYPE x, TYPE y) {                                                  \
    MPFR_SET_FLT(x);                                                           \
    MPFR_SET_FLT(y);                                                           \
    mpfr_##FUNCTION(mpfr_x, mpfr_y, mpfr_x, MPFR_RNDN);                        \
    typeof(x) ret = MPFR_GET_FLT(x);                                           \
    return ret;                                                                \
  }

#define DEFINE_SINCOS_WRAPPER(NAME, TYPE)                                      \
  void NAME(TYPE x, TYPE *o1, TYPE *o2) {                                      \
    MPFR_DECL_INIT(mpfr_o1, BINARY128_PREC);                                   \
    MPFR_DECL_INIT(mpfr_o2, BINARY128_PREC);                                   \
    MPFR_SET_FLT(x);                                                           \
    mpfr_sin_cos(mpfr_o1, mpfr_o2, mpfr_x, MPFR_RNDN);                         \
    *o1 = MPFR_GET_FLT(o1);                                                    \
    *o2 = MPFR_GET_FLT(o2);                                                    \
  }

DEFINE_1_WRAPPER(sqrtf, float, sqrt);
DEFINE_1_WRAPPER(sqrt, double, sqrt);

DEFINE_1_WRAPPER(cbrtf, float, cbrt);
DEFINE_1_WRAPPER(cbrt, double, cbrt);

DEFINE_2_WRAPPER(hypotf, float, hypot);
DEFINE_2_WRAPPER(hypot, double, hypot);

DEFINE_1_WRAPPER(log, double, log);
DEFINE_1_WRAPPER(logf, float, log);

DEFINE_1_WRAPPER(log10, double, log10);
DEFINE_1_WRAPPER(log10f, float, log10);

DEFINE_1_WRAPPER(log1p, double, log1p);
DEFINE_1_WRAPPER(log1pf, float, log1p);

DEFINE_1_WRAPPER(log2, double, log2);
DEFINE_1_WRAPPER(log2f, float, log2);

DEFINE_1_WRAPPER(sin, double, sin);
DEFINE_1_WRAPPER(sinf, float, sin);

DEFINE_1_WRAPPER(asin, double, asin);
DEFINE_1_WRAPPER(asinf, float, asin);

DEFINE_1_WRAPPER(asinh, double, asinh);
DEFINE_1_WRAPPER(asinhf, float, asinh);

DEFINE_1_WRAPPER(cos, double, cos);
DEFINE_1_WRAPPER(cosf, float, cos);

DEFINE_1_WRAPPER(acos, double, acos);
DEFINE_1_WRAPPER(acosf, float, acos);

DEFINE_1_WRAPPER(acosh, double, acosh);
DEFINE_1_WRAPPER(acoshf, float, acosh);

DEFINE_1_WRAPPER(atan, double, atan);
DEFINE_1_WRAPPER(atanf, float, atan);

DEFINE_1_WRAPPER(atanh, double, atanh);
DEFINE_1_WRAPPER(atanhf, float, atanh);

DEFINE_2_WRAPPER(atan2, double, atan2);
DEFINE_2_WRAPPER(atan2f, float, atan2);

DEFINE_1_WRAPPER(exp, double, exp);
DEFINE_1_WRAPPER(expf, float, exp);

DEFINE_2_WRAPPER(pow, double, pow);
DEFINE_2_WRAPPER(powf, float, pow);

DEFINE_1_WRAPPER(exp10, double, exp10);
DEFINE_1_WRAPPER(exp10f, float, exp10);

DEFINE_1_WRAPPER(exp2, double, exp2);
DEFINE_1_WRAPPER(exp2f, float, exp2);

DEFINE_1_WRAPPER(expm1, double, expm1);
DEFINE_1_WRAPPER(expm1f, float, expm1);

DEFINE_1_WRAPPER(j0, double, j0);
DEFINE_1_WRAPPER(j0f, float, j0);

DEFINE_1_WRAPPER(j1, double, j1);
DEFINE_1_WRAPPER(j1f, float, j1);

DEFINE_1i_1_WRAPPER(jn, double, jn);
DEFINE_1i_1_WRAPPER(jnf, float, jn);

DEFINE_1_WRAPPER(y0, double, y0);
DEFINE_1_WRAPPER(y0f, float, y0);

DEFINE_1_WRAPPER(y1, double, y1);
DEFINE_1_WRAPPER(y1f, float, y1);

DEFINE_1i_1_WRAPPER(yn, double, yn);
DEFINE_1i_1_WRAPPER(ynf, float, yn);

DEFINE_1_WRAPPER(erf, double, erf);
DEFINE_1_WRAPPER(erff, float, erf);

DEFINE_1_WRAPPER(erfc, double, erfc);
DEFINE_1_WRAPPER(erfcf, float, erfc);

DEFINE_1_1p_WRAPPER(lgamma_r, double, lgamma);
DEFINE_1_1p_WRAPPER(lgammaf_r, float, lgamma);

DEFINE_SINCOS_WRAPPER(sincos, double);
DEFINE_SINCOS_WRAPPER(sincosf, float);

// Handle glibc's lgamma separately as it's not available in MPFR

double lgamma(double x) { return lgamma_r(x, &signgam); }

float lgammaf(float x) { return lgammaf_r(x, &signgam); }

// tgamma doesn't seem to be available in MPFR

double tgamma(double x) {
  printf("tgamma is not available in wrap-mpfr.\n");
  exit(1);
}

float tgamma_f(float x) {
  printf("tgamma is not available in wrap-mpfr.\n");
  exit(1);
}