#define _GNU_SOURCE
#include <stdio.h>
#include <mpfr.h>
#include <stdlib.h>
#include <math.h>

#define FLOAT_PREC 24
#define FLOAT_EMIN -148
#define FLOAT_EMAX 128

#define DOUBLE_PREC 53
#define DOUBLE_EMIN -1073
#define DOUBLE_EMAX 1024

#define DEFINE_1_WRAPPER_FLOAT(WRAP_NAME, MPFR_NAME)                           \
  float WRAP_NAME(float x) {                                                                  \
    mpfr_set_emin(FLOAT_EMIN);                                                                    \
    mpfr_set_emax(FLOAT_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    float ret;                                                                               \
    mpfr_init2 (yy, FLOAT_PREC);                                                                  \
    mpfr_set_flt (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, yy, MPFR_RNDN); /* for rounding to nearest */              \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_flt (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1_WRAPPER_DOUBLE(WRAP_NAME, MPFR_NAME)                           \
  double WRAP_NAME(double x) {                                                                  \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(DOUBLE_EMIN);                                                                    \
    mpfr_set_emax(DOUBLE_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    double ret;                                                                               \
    mpfr_init2 (yy, DOUBLE_PREC);                                                                  \
    mpfr_set_d (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, yy, MPFR_RNDN); /* for rounding to nearest */              \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_d (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1i_1_WRAPPER_FLOAT(WRAP_NAME, MPFR_NAME)                        \
  float WRAP_NAME(int n, float x) {                                                           \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(FLOAT_EMIN);                                                                    \
    mpfr_set_emax(FLOAT_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    float ret;                                                                               \
    mpfr_init2 (yy, FLOAT_PREC);                                                                  \
    mpfr_set_flt (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, n, yy, MPFR_RNDN); /* for rounding to nearest */           \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_flt (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1i_1_WRAPPER_DOUBLE(WRAP_NAME, MPFR_NAME)                        \
  double WRAP_NAME(int n, double x) {                                                           \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(DOUBLE_EMIN);                                                                    \
    mpfr_set_emax(DOUBLE_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    double ret;                                                                               \
    mpfr_init2 (yy, DOUBLE_PREC);                                                                  \
    mpfr_set_d (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, n, yy, MPFR_RNDN); /* for rounding to nearest */           \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_d (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1_1p_WRAPPER_FLOAT(WRAP_NAME, MPFR_NAME)                        \
  float WRAP_NAME(float x, int *s) {                                                          \
  /* MPFR initialization, should be done only once */                                       \
    mpfr_set_emin(FLOAT_EMIN);                                                                    \
    mpfr_set_emax(FLOAT_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    float ret;                                                                               \
    mpfr_init2 (yy, FLOAT_PREC);                                                                  \
    mpfr_set_flt (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, s, yy, MPFR_RNDN); /* for rounding to nearest */           \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_flt (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_1_1p_WRAPPER_DOUBLE(WRAP_NAME, MPFR_NAME)                        \
  double WRAP_NAME(double x, int *s) {                                                          \
  /* MPFR initialization, should be done only once */                                       \
    mpfr_set_emin(DOUBLE_EMIN);                                                                    \
    mpfr_set_emax(DOUBLE_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    double ret;                                                                               \
    mpfr_init2 (yy, DOUBLE_PREC);                                                                  \
    mpfr_set_d (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, s, yy, MPFR_RNDN); /* for rounding to nearest */           \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_d (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    return ret;                                                                             \
  }

#define DEFINE_2_WRAPPER_FLOAT(WRAP_NAME, MPFR_NAME)                           \
  float WRAP_NAME(float x, float y) {                                                          \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(FLOAT_EMIN);                                                                    \
    mpfr_set_emax(FLOAT_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    mpfr_t xx;                                                                              \
    float ret;                                                                               \
    mpfr_init2 (yy, FLOAT_PREC);                                                                  \
    mpfr_init2 (xx, FLOAT_PREC);                                                                  \
    mpfr_set_flt (xx, x, MPFR_RNDN);                                                    \
    mpfr_set_flt (yy, y, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, xx, yy, MPFR_RNDN); /* for rounding to nearest */          \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_flt (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    mpfr_clear(xx);                                                                         \
    return ret;                                                                             \
  }

#define DEFINE_2_WRAPPER_DOUBLE(WRAP_NAME, MPFR_NAME)                           \
  double WRAP_NAME(double x, double y) {                                                          \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(DOUBLE_EMIN);                                                                    \
    mpfr_set_emax(DOUBLE_EMAX);                                                                     \
    int inex;                                                                               \
    mpfr_t yy;                                                                              \
    mpfr_t xx;                                                                              \
    double ret;                                                                               \
    mpfr_init2 (yy, DOUBLE_PREC);                                                                  \
    mpfr_init2 (xx, DOUBLE_PREC);                                                                  \
    mpfr_set_d (xx, x, MPFR_RNDN);                                                    \
    mpfr_set_d (yy, y, MPFR_RNDN);                                                    \
    inex = mpfr_##MPFR_NAME (yy, xx, yy, MPFR_RNDN); /* for rounding to nearest */          \
    mpfr_subnormalize (yy, inex, MPFR_RNDN);                                                \
    ret = mpfr_get_d (yy, MPFR_RNDN);                                                 \
    mpfr_clear (yy);                                                                        \
    mpfr_clear(xx);                                                                         \
    return ret;                                                                             \
  }

#define DEFINE_SINCOS_WRAPPER_FLOAT(WRAP_NAME)                                 \
  void WRAP_NAME(float x, float *o1, float *o2) {                                              \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(FLOAT_EMIN);                                                                    \
    mpfr_set_emax(FLOAT_EMIN);                                                                     \
    int inex;                                                                               \
    mpfr_t yy, sop, cop;                                                                    \
    mpfr_init2 (yy, FLOAT_PREC);                                                                  \
    mpfr_init2 (sop, FLOAT_PREC);                                                                 \
    mpfr_init2 (cop, FLOAT_PREC);                                                                 \
    mpfr_set_flt (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_sin_cos (sop, cop, yy, MPFR_RNDN); /* for rounding to nearest */            \
    mpfr_subnormalize (sop, inex, MPFR_RNDN);                                               \
    mpfr_subnormalize (cop, inex, MPFR_RNDN);                                               \
    *o1 = mpfr_get_flt (sop, MPFR_RNDN);                                                \
    *o2 = mpfr_get_flt (cop, MPFR_RNDN);                                                \
    mpfr_clear (yy);                                                                        \
    mpfr_clear (sop);                                                                       \
    mpfr_clear (cop);                                                                       \
  }

#define DEFINE_SINCOS_WRAPPER_DOUBLE(WRAP_NAME)                                 \
  void WRAP_NAME(double x, double *o1, double *o2) {                                              \
    /* MPFR initialization, should be done only once */                                     \
    mpfr_set_emin(DOUBLE_EMIN);                                                                    \
    mpfr_set_emax(DOUBLE_EMIN);                                                                     \
    int inex;                                                                               \
    mpfr_t yy, sop, cop;                                                                    \
    mpfr_init2 (yy,  DOUBLE_PREC);                                                                  \
    mpfr_init2 (sop, DOUBLE_PREC);                                                                 \
    mpfr_init2 (cop, DOUBLE_PREC);                                                                 \
    mpfr_set_d (yy, x, MPFR_RNDN);                                                    \
    inex = mpfr_sin_cos (sop, cop, yy, MPFR_RNDN); /* for rounding to nearest */            \
    mpfr_subnormalize (sop, inex, MPFR_RNDN);                                               \
    mpfr_subnormalize (cop, inex, MPFR_RNDN);                                               \
    *o1 = mpfr_get_d (sop, MPFR_RNDN);                                                \
    *o2 = mpfr_get_d (cop, MPFR_RNDN);                                                \
    mpfr_clear (yy);                                                                        \
    mpfr_clear (sop);                                                                       \
    mpfr_clear (cop);                                                                       \
  }


DEFINE_1_WRAPPER_DOUBLE(sqrt, sqrt);
DEFINE_1_WRAPPER_FLOAT(sqrtf, sqrt);

DEFINE_1_WRAPPER_DOUBLE(cbrt, cbrt);
DEFINE_1_WRAPPER_FLOAT(cbrtf, cbrt);

DEFINE_2_WRAPPER_DOUBLE(hypot, hypot);
DEFINE_2_WRAPPER_FLOAT(hypotf, hypot);

DEFINE_1_WRAPPER_DOUBLE(log, log);
DEFINE_1_WRAPPER_FLOAT(logf, log);

DEFINE_1_WRAPPER_DOUBLE(log10, log10);
DEFINE_1_WRAPPER_FLOAT(log10f, log10);

DEFINE_1_WRAPPER_DOUBLE(log1p, log1p);
DEFINE_1_WRAPPER_FLOAT(log1pf, log1p);

DEFINE_1_WRAPPER_DOUBLE(log2, log2);
DEFINE_1_WRAPPER_FLOAT(log2f, log2);

DEFINE_1_WRAPPER_DOUBLE(sin, sin);
DEFINE_1_WRAPPER_FLOAT(sinf, sin);

DEFINE_1_WRAPPER_DOUBLE(asin, asin);
DEFINE_1_WRAPPER_FLOAT(asinf, asin);

DEFINE_1_WRAPPER_DOUBLE(asinh, asinh);
DEFINE_1_WRAPPER_FLOAT(asinhf, asinh);

DEFINE_1_WRAPPER_DOUBLE(cos, cos);
DEFINE_1_WRAPPER_FLOAT(cosf, cos);

DEFINE_1_WRAPPER_DOUBLE(acos, acos);
DEFINE_1_WRAPPER_FLOAT(acosf, acos);

DEFINE_1_WRAPPER_DOUBLE(acosh, acosh);
DEFINE_1_WRAPPER_FLOAT(acoshf, acosh);

DEFINE_1_WRAPPER_DOUBLE(atan, atan);
DEFINE_1_WRAPPER_FLOAT(atanf, atan);

DEFINE_1_WRAPPER_DOUBLE(atanh, atanh);
DEFINE_1_WRAPPER_FLOAT(atanhf, atanh);

DEFINE_2_WRAPPER_DOUBLE(atan2, atan2);
DEFINE_2_WRAPPER_FLOAT(atan2f, atan2);

DEFINE_1_WRAPPER_DOUBLE(exp, exp);
DEFINE_1_WRAPPER_FLOAT(expf, exp);

DEFINE_2_WRAPPER_DOUBLE(pow, pow);
DEFINE_2_WRAPPER_FLOAT(powf, pow);

DEFINE_1_WRAPPER_DOUBLE(exp10, exp10);
DEFINE_1_WRAPPER_FLOAT(exp10f, exp10);

DEFINE_1_WRAPPER_DOUBLE(exp2, exp2);
DEFINE_1_WRAPPER_FLOAT(exp2f, exp2);

DEFINE_1_WRAPPER_DOUBLE(expm1, expm1);
DEFINE_1_WRAPPER_FLOAT(expm1f, expm1);

DEFINE_1_WRAPPER_DOUBLE(j0, j0);
DEFINE_1_WRAPPER_FLOAT(j0f, j0);

DEFINE_1_WRAPPER_DOUBLE(j1, j1);
DEFINE_1_WRAPPER_FLOAT(j1f, j1);

DEFINE_1i_1_WRAPPER_DOUBLE(jn, jn);
DEFINE_1i_1_WRAPPER_FLOAT(jnf, jn);

DEFINE_1_WRAPPER_DOUBLE(y0, y0);
DEFINE_1_WRAPPER_FLOAT(y0f, y0);

DEFINE_1_WRAPPER_DOUBLE(y1, y1);
DEFINE_1_WRAPPER_FLOAT(y1f, y1);

DEFINE_1i_1_WRAPPER_DOUBLE(yn, yn);
DEFINE_1i_1_WRAPPER_FLOAT(ynf, yn);

DEFINE_1_WRAPPER_DOUBLE(erf, erf);
DEFINE_1_WRAPPER_FLOAT(erff, erf);

DEFINE_1_WRAPPER_DOUBLE(erfc, erfc);
DEFINE_1_WRAPPER_FLOAT(erfcf, erfc);

DEFINE_1_1p_WRAPPER_DOUBLE(lgamma_r, lgamma);
DEFINE_1_1p_WRAPPER_FLOAT(lgammaf_r, lgamma);

DEFINE_SINCOS_WRAPPER_DOUBLE(sincos);
DEFINE_SINCOS_WRAPPER_FLOAT(sincosf);

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