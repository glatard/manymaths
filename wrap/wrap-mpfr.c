#define _GNU_SOURCE
#include <stdio.h>
#include <mpfr.h>
#include <stdlib.h>
#include <math.h>

#define DEFINE_1_WRAPPER(WRAP_NAME, MPFR_NAME, TYPE, PREC, ABBRV)                           \
  TYPE WRAP_NAME(TYPE x) {                                                                  \
    /* MPFR initialization, should be done only once */                                        \
    mpfr_set_emin(-148);                                                                    \
    mpfr_set_emax(128);                                                                         \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    TYPE ret;                                                                               \
    mpfr_init2 (yy, PREC);                                                                  \
    mpfr_set_##ABBRV (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, yy, MPFR_RNDN); /* for rounding to nearest */              \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_##ABBRV (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1i_1_WRAPPER(WRAP_NAME, MPFR_NAME, TYPE, PREC, ABBRV)                                        \
  TYPE WRAP_NAME(int n, TYPE x) {                                                                \
    /* MPFR initialization, should be done only once */                                        \
    mpfr_set_emin(-148);                                                                    \
    mpfr_set_emax(128);                                                                         \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    TYPE ret;                                                                               \
    mpfr_init2 (yy, PREC);                                                                  \
    mpfr_set_##ABBRV (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, n, yy, MPFR_RNDN); /* for rounding to nearest */                \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_##ABBRV (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1_1p_WRAPPER(WRAP_NAME, MPFR_NAME, TYPE, PREC, ABBRV)                                        \
  TYPE WRAP_NAME(TYPE x, int *s) {                                                               \
  /* MPFR initialization, should be done only once */                                        \
    mpfr_set_emin(-148);                                                                    \
    mpfr_set_emax(128);                                                                         \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    TYPE ret;                                                                               \
    mpfr_init2 (yy, PREC);                                                                  \
    mpfr_set_##ABBRV (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, s, yy, MPFR_RNDN); /* for rounding to nearest */                \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_##ABBRV (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_2_WRAPPER(WRAP_NAME, MPFR_NAME, TYPE, PREC, ABBRV)                                           \
  TYPE WRAP_NAME(TYPE x, TYPE y) {                                                               \
    /* MPFR initialization, should be done only once */                                        \
    mpfr_set_emin(-148);                                                                    \
    mpfr_set_emax(128);                                                                         \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    mpfr_t xx;                                                                              \
    TYPE ret;                                                                               \
    mpfr_init2 (yy, PREC);                                                                  \
    mpfr_init2 (xx, PREC);                                                                  \
    mpfr_set_##ABBRV (xx, x, MPFR_RNDN);                                                    \
    mpfr_set_##ABBRV (yy, y, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, xx, yy, MPFR_RNDN); /* for rounding to nearest */               \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_##ABBRV (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    mpfr_clear(xx);                                                                         \
    return ret;                                                                             \
  }

#define DEFINE_SINCOS_WRAPPER(WRAP_NAME, TYPE, PREC, ABBRV)                                        \
  void WRAP_NAME(TYPE x, TYPE *o1, TYPE *o2) {                                                   \
    /* MPFR initialization, should be done only once */                                        \
    mpfr_set_emin(-148);                                                                    \
    mpfr_set_emax(128);                                                                         \
    int inex;                                                                               \
    mpfr_t yy, sop, cop;                                                                    \
    mpfr_init2 (yy, PREC);                                                                  \
    mpfr_init2 (sop, PREC);                                                                  \
    mpfr_init2 (cop, PREC);                                                                  \
    mpfr_set_##ABBRV (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_sin_cos (sop, cop, yy, MPFR_RNDN); /* for rounding to nearest */             \
    mpfr_subnormalize (sop, inex, MPFR_RNDN);                                                \
    mpfr_subnormalize (cop, inex, MPFR_RNDN);                                                \
    *o1 = mpfr_get_##ABBRV (sop, MPFR_RNDN);                                                 \
    *o2 = mpfr_get_##ABBRV (cop, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    mpfr_clear (sop);                                                                        \
    mpfr_clear (cop);                                                                        \
  }

DEFINE_1_WRAPPER(sqrt, sqrt, double, 53, d);
DEFINE_1_WRAPPER(sqrtf, sqrt, float, 24, flt);

DEFINE_1_WRAPPER(cbrt, cbrt, double, 53, d);
DEFINE_1_WRAPPER(cbrtf, cbrt, float, 24, flt);

DEFINE_2_WRAPPER(hypot, hypot, double, 53, d);
DEFINE_2_WRAPPER(hypotf, hypot, float, 24, flt);

DEFINE_1_WRAPPER(log, log, double, 53, d);
DEFINE_1_WRAPPER(logf, log, float, 24, flt);

DEFINE_1_WRAPPER(log10, log10, double, 53, d);
DEFINE_1_WRAPPER(log10f, log10, float, 24, flt);

DEFINE_1_WRAPPER(log1p, log1p, double, 53, d);
DEFINE_1_WRAPPER(log1pf, log1p, float, 24, flt);

DEFINE_1_WRAPPER(log2, log2, double, 53, d);
DEFINE_1_WRAPPER(log2f, log2, float, 24, flt);

DEFINE_1_WRAPPER(sin, sin, double, 53, d);
DEFINE_1_WRAPPER(sinf, sin, float, 24, flt);

DEFINE_1_WRAPPER(asin, asin, double, 53, d);
DEFINE_1_WRAPPER(asinf, asin, float, 24, flt);

DEFINE_1_WRAPPER(asinh, asinh, double, 53, d);
DEFINE_1_WRAPPER(asinhf, asinh, float, 24, flt);

DEFINE_1_WRAPPER(cos, cos, double, 53, d);
DEFINE_1_WRAPPER(cosf, cos, float, 24, flt);

DEFINE_1_WRAPPER(acos, acos, double, 53, d);
DEFINE_1_WRAPPER(acosf, acos, float, 24, flt);

DEFINE_1_WRAPPER(acosh, acosh, double, 53, d);
DEFINE_1_WRAPPER(acoshf, acosh, float, 24, flt);

DEFINE_1_WRAPPER(atan, atan, double, 53, d);
DEFINE_1_WRAPPER(atanf, atan, float, 24, flt);

DEFINE_1_WRAPPER(atanh, atanh, double, 53, d);
DEFINE_1_WRAPPER(atanhf, atanh, float, 24, flt);

DEFINE_2_WRAPPER(atan2, atan2, double, 53, d);
DEFINE_2_WRAPPER(atan2f, atan2, float, 24, flt);

DEFINE_1_WRAPPER(exp, exp, double, 53, d);
DEFINE_1_WRAPPER(expf, exp, float, 24, flt);

DEFINE_2_WRAPPER(pow, pow, double, 53, d);
DEFINE_2_WRAPPER(powf, pow, float, 24, flt);

DEFINE_1_WRAPPER(exp10, exp10, double, 53, d);
DEFINE_1_WRAPPER(exp10f, exp10, float, 24, flt);

DEFINE_1_WRAPPER(exp2, exp2, double, 53, d);
DEFINE_1_WRAPPER(exp2f, exp2, float, 24, flt);

DEFINE_1_WRAPPER(expm1, expm1, double, 53, d);
DEFINE_1_WRAPPER(expm1f, expm1, float, 24, flt);

DEFINE_1_WRAPPER(j0, j0, double, 53, d);
DEFINE_1_WRAPPER(j0f, j0, float, 24, flt);

DEFINE_1_WRAPPER(j1, j1, double, 53, d);
DEFINE_1_WRAPPER(j1f, j1, float, 24, flt);

DEFINE_1i_1_WRAPPER(jn, jn, double, 53, d);
DEFINE_1i_1_WRAPPER(jnf, jn, float, 24, flt);

DEFINE_1_WRAPPER(y0, y0, double, 53, d);
DEFINE_1_WRAPPER(y0f, y0, float, 24, flt);

DEFINE_1_WRAPPER(y1, y1, double, 53, d);
DEFINE_1_WRAPPER(y1f, y1, float, 24, flt);

DEFINE_1i_1_WRAPPER(yn, yn, double, 53, d);
DEFINE_1i_1_WRAPPER(ynf, yn, float, 24, flt);

DEFINE_1_WRAPPER(erf, erf, double, 53, d);
DEFINE_1_WRAPPER(erff, erf, float, 24, flt);

DEFINE_1_WRAPPER(erfc, erfc, double, 53, d);
DEFINE_1_WRAPPER(erfcf, erfc, float, 24, flt);

DEFINE_1_1p_WRAPPER(lgamma_r, lgamma, double, 53, d);
DEFINE_1_1p_WRAPPER(lgammaf_r, lgamma, float, 24, flt);

DEFINE_SINCOS_WRAPPER(sincos, double, 53, d);
DEFINE_SINCOS_WRAPPER(sincosf, float, 24, flt);

// Handle glibc's lgamma separately as it's not available in MPFR

double lgamma(double x)
{
  return lgamma_r(x, &signgam);
}

float lgammaf(float x)
{
  return lgammaf_r(x, &signgam);
}

// tgamma doesn't seem to be available in MPFR

double tgamma(double x)
{
  printf("tgamma is not available in wrap-mpfr.\n");
  exit(1);
}

float tgamma_f(float x)
{
  printf("tgamma is not available in wrap-mpfr.\n");
  exit(1);
}

