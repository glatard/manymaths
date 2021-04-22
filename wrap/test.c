#include <math.h>
#include <stdio.h>

int main()
{
        double x = 0.2;
        double a = cosf(x);
        a = cos(x);
        printf("%0.55f\n",a);
        a = sinf(x);
        printf("%0.55f\n",a);
        a = sin(x);
        printf("%0.55f\n",a);
        a = log(x);
        printf("%0.55f\n",a);
        printf("done\n");
        return 0;
}

