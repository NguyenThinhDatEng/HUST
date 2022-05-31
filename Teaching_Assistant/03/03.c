#include <stdio.h>

int main()
{
    double x, y;
    scanf("%lf%lf", &x, &y);
    printf("%lf\n", x * x + y * y);
    printf("%lf\n", (x + y) * (x + y));
    printf("%lf", (x - y) * (x - y));
    return 0;
}
