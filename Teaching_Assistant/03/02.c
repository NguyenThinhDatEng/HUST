#include <stdio.h>

int main()
{
    double r;
    scanf("%lf", &r);
    if (r <= 0)
        printf("ERROR");
    else
    {
        float const PI = 3.14159;
        double M, S;
        M = 2 * PI * r;
        S = PI * r * r;
        printf("%lf\n%lf", M, S);
    }
    return 0;
}
