#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;
    scanf("%lf%lf", &x, &y);
    double F;
    // way 01
    // if (x == y)
    //     F = 7 * pow(x, 6);
    // else
    //     F = F * (pow(x, 7) - pow(y, 7)) / (x - y);
    // way 02
    // F = pow(x, 6) + pow(y, 4) * x * x + pow(x, 3) * pow(y, 3) + y * pow(x, 5) + pow(y, 5) * x + y * y * pow(x, 4) + pow(y, 6);
    // way 03
    F = pow(x, 6) + pow(y, 6) + y * pow(x, 5) + y * y * pow(x, 4) + pow(x, 3) * pow(y, 3) + pow(y, 4) * x * x + pow(y, 5) * x;
    printf("%lf", F);
    return 0;
}