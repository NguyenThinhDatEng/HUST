#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    if (n <= 0)
        printf("Error");
    else
    {
        if (x == 1)
            printf("%d", n + 1);
        else
            printf("%lf", (1 - pow(x, n + 1)) / (1 - x));
    }
    return 0;
}
