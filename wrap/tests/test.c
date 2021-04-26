#define _GNU_SOURCE
#include <math.h>
#include <stdio.h>

void test(double x)
{
        printf("sqrt(%0.55f)=%0.55f\n", x,  sqrt(x));
        printf("sqrtf(%0.55f)=%0.55f\n", x, sqrtf(x));
        printf("cbrt(%0.55f)=%0.55f\n", x,  cbrt(x));
        printf("cbrtf(%0.55f)=%0.55f\n", x, cbrtf(x));
        printf("hypot(%0.55f, %0.55f)=%0.55f\n", x, x, hypot(x, x));
        printf("hypotf(%0.55f, %0.55f)=%0.55f\n", x, x, hypotf(x, x));
        printf("log(%0.55f)=%0.55f\n", x,  log(x));
        printf("logf(%0.55f)=%0.55f\n", x, logf(x));
        printf("log10(%0.55f)=%0.55f\n", x,  log10(x));
        printf("log10f(%0.55f)=%0.55f\n", x, log10f(x));
        printf("log2(%0.55f)=%0.55f\n", x,  log2(x));
        printf("log2f(%0.55f)=%0.55f\n", x, log2f(x));
        printf("sin(%0.55f)=%0.55f\n", x,  sin(x));
        printf("sinf(%0.55f)=%0.55f\n", x, sinf(x));
        printf("asin(%0.55f)=%0.55f\n", x,  asin(x));
        printf("asinf(%0.55f)=%0.55f\n", x, asinf(x));
        printf("cos(%0.55f)=%0.55f\n", x,  cos(x));
        printf("cosf(%0.55f)=%0.55f\n", x, cosf(x));
        printf("acos(%0.55f)=%0.55f\n", x,  acos(x));
        printf("acosf(%0.55f)=%0.55f\n", x, acosf(x));
        printf("acosh(1+%0.55f)=%0.55f\n", x,  acosh(1+x));
        printf("acoshf(1+%0.55f)=%0.55f\n", x, acoshf(1+x));
        printf("atan(%0.55f)=%0.55f\n", x,  atan(x));
        printf("atanf(%0.55f)=%0.55f\n", x, atanf(x));
        printf("atanh(%0.55f)=%0.55f\n", x,  atanh(x));
        printf("atanhf(%0.55f)=%0.55f\n", x, atanhf(x));
        printf("atan2(%0.55f, %0.55f)=%0.55f\n", x, x, atan2(x, x));
        printf("atan2f(%0.55f, %0.55f)=%0.55f\n", x, x, atan2f(x, x));
        printf("exp(%0.55f)=%0.55f\n", x,  exp(x));
        printf("expf(%0.55f)=%0.55f\n", x, expf(x));
        printf("pow(%0.55f, %0.55f)=%0.55f\n", x, x, pow(x, x));
        printf("powf(%0.55f, %0.55f)=%0.55f\n", x, x, powf(x, x));
        printf("exp10(%0.55f)=%0.55f\n", x,  exp10(x));
        printf("exp10f(%0.55f)=%0.55f\n", x, exp10f(x));
        printf("exp2(%0.55f)=%0.55f\n", x,  exp2(x));
        printf("exp2f(%0.55f)=%0.55f\n", x, exp2f(x));
        printf("expm1(%0.55f)=%0.55f\n", x,  expm1(x));
        printf("expm1f(%0.55f)=%0.55f\n", x, expm1f(x));
        printf("j0(%0.55f)=%0.55f\n", x,  j0(x));
        printf("j0f(%0.55f)=%0.55f\n", x, j0f(x));
        printf("j1(%0.55f)=%0.55f\n", x,  j1(x));
        printf("j1f(%0.55f)=%0.55f\n", x, j1f(x));
        printf("jn(%0.55f)=%0.55f\n", x,  jn(x, 5));
        printf("jnf(%0.55f)=%0.55f\n", x, jnf(x, 5));
        printf("y0(%0.55f)=%0.55f\n", x,  y0(x));
        printf("y0f(%0.55f)=%0.55f\n", x, y0f(x));
        printf("y1(%0.55f)=%0.55f\n", x,  y1(x));
        printf("y1f(%0.55f)=%0.55f\n", x, y1f(x));
        printf("yn(%0.55f)=%0.55f\n", x,  yn(x, 5));
        printf("ynf(%0.55f)=%0.55f\n", x, ynf(x, 5));
        printf("erf(%0.55f)=%0.55f\n", x,  erf(x));
        printf("erff(%0.55f)=%0.55f\n", x, erff(x));
        printf("erfc(%0.55f)=%0.55f\n", x,  erfc(x));
        printf("erfcf(%0.55f)=%0.55f\n", x, erfcf(x));
        printf("lgamma(%0.55f)=%0.55f\n", x,  lgamma(x));
        printf("lgammaf(%0.55f)=%0.55f\n", x, lgammaf(x));
        int sgn;
        printf("lgamma_r(%0.55f)=%0.55f\n", x,  lgamma_r(x, &sgn));
        printf("lgammaf_r(%0.55f)=%0.55f\n", x, lgammaf_r(x, &sgn));
        double sin_x, cos_x;
        sincos(x, &sin_x, &cos_x);
        printf("sincos(%0.55f)=%0.55f,%0.55f\n", x, sin_x, cos_x);
        float sin_xf, cos_xf;
        sincosf(x, &sin_xf, &cos_xf);
        printf("sincosf(%0.55f)=%0.55f\n", x, sin_xf, cos_xf);
        printf("tgamma(%0.55f)=%0.55f\n", x, tgamma(x));
        printf("tgammaf(%0.55f)=%0.55f\n", x, tgammaf(x));
}

int main()
{
        double x = 0.123456789;
        test(x);
        return 0;
}
