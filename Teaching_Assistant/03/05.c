#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    double F, tmp;
    scanf("%lf%lf%lf", &x, &y, &z);
    F = x + y + z;
    tmp = x * x + y * y + 1;
    F = F / tmp;
    tmp = fabs(x - z * cos(y));
    F = F - tmp;
    printf("%lf", F);
}