#define _GNU_SOURCE
#include <math.h>
#include <stdio.h>

void test(double x) {
  printf("sqrt(%13a) =%13a\n", x, sqrt(x));
  printf("sqrtf(%13a)=%13a\n", x, sqrtf(x));
  printf("cbrt(%13a) =%13a\n", x, cbrt(x));
  printf("cbrtf(%13a)=%13a\n", x, cbrtf(x));
  printf("hypot(%13a, %13a) =%13a\n", x, x, hypot(x, x));
  printf("hypotf(%13a, %13a)=%13a\n", x, x, hypotf(x, x));
  printf("log(%13a) =%13a\n", x, log(x));
  printf("logf(%13a)=%13a\n", x, logf(x));
  printf("log10(%13a) =%13a\n", x, log10(x));
  printf("log10f(%13a)=%13a\n", x, log10f(x));
  printf("log2(%13a) =%13a\n", x, log2(x));
  printf("log2f(%13a)=%13a\n", x, log2f(x));
  printf("sin(%13a) =%13a\n", x, sin(x));
  printf("sinf(%13a)=%13a\n", x, sinf(x));
  printf("asin(%13a) =%13a\n", x, asin(x));
  printf("asinf(%13a)=%13a\n", x, asinf(x));
  printf("cos(%13a) =%13a\n", x, cos(x));
  printf("cosf(%13a)=%13a\n", x, cosf(x));
  printf("acos(%13a) =%13a\n", x, acos(x));
  printf("acosf(%13a)=%13a\n", x, acosf(x));
  printf("acosh(1+%13a) =%13a\n", x, acosh(1 + x));
  printf("acoshf(1+%13a)=%13a\n", x, acoshf(1 + x));
  printf("atan(%13a) =%13a\n", x, atan(x));
  printf("atanf(%13a)=%13a\n", x, atanf(x));
  printf("atanh(%13a) =%13a\n", x, atanh(x));
  printf("atanhf(%13a)=%13a\n", x, atanhf(x));
  printf("atan2(%13a, %13a) =%13a\n", x, x, atan2(x, x));
  printf("atan2f(%13a, %13a)=%13a\n", x, x, atan2f(x, x));
  printf("exp(%13a) =%13a\n", x, exp(x));
  printf("expf(%13a)=%13a\n", x, expf(x));
  printf("pow(%13a, %13a) =%13a\n", x, x, pow(x, x));
  printf("powf(%13a, %13a)=%13a\n", x, x, powf(x, x));
  // exp10 isn't in openlibm so we don't test it
//   printf("exp10(%13a) =%13a\n", x, exp10(x));
//   printf("exp10f(%13a)=%13a\n", x, exp10f(x));
  printf("exp2(%13a) =%13a\n", x, exp2(x));
  printf("exp2f(%13a)=%13a\n", x, exp2f(x));
  printf("expm1(%13a) =%13a\n", x, expm1(x));
  printf("expm1f(%13a)=%13a\n", x, expm1f(x));
  printf("j0(%13a) =%13a\n", x, j0(x));
  printf("j0f(%13a)=%13a\n", x, j0f(x));
  printf("j1(%13a) =%13a\n", x, j1(x));
  printf("j1f(%13a)=%13a\n", x, j1f(x));
  printf("jn(%13a) =%13a\n", x, jn(x, 5));
  printf("jnf(%13a)=%13a\n", x, jnf(x, 5));
  printf("y0(%13a) =%13a\n", x, y0(x));
  printf("y0f(%13a)=%13a\n", x, y0f(x));
  printf("y1(%13a) =%13a\n", x, y1(x));
  printf("y1f(%13a)=%13a\n", x, y1f(x));
  printf("yn(%13a) =%13a\n", x, yn(x, 5));
  printf("ynf(%13a)=%13a\n", x, ynf(x, 5));
  printf("erf(%13a) =%13a\n", x, erf(x));
  printf("erff(%13a)=%13a\n", x, erff(x));
  printf("erfc(%13a) =%13a\n", x, erfc(x));
  printf("erfcf(%13a)=%13a\n", x, erfcf(x));
  printf("lgamma(%13a) =%13a\n", x, lgamma(x));
  printf("lgammaf(%13a)=%13a\n", x, lgammaf(x));
  int sgn;
  printf("lgamma_r(%13a) =%13a\n", x, lgamma_r(x, &sgn));
  printf("lgammaf_r(%13a)=%13a\n", x, lgammaf_r(x, &sgn));
  double sin_x, cos_x;
  sincos(x, &sin_x, &cos_x);
  printf("sincos(%13a) =%13a,%13a\n", x, sin_x, cos_x);
  float sin_xf, cos_xf;
  sincosf(x, &sin_xf, &cos_xf);
  printf("sincosf(%13a)=%13a,%13a\n", x, sin_xf, cos_xf);
  printf("tgamma(%13a) =%13a\n", x, tgamma(x));
  printf("tgammaf(%13a)=%13a\n", x, tgammaf(x));
}

int main() {
  double x = 0.123456789;
  test(x);
  return 0;
}
