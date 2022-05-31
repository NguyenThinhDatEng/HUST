#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    int n;
    scanf("%lf%d", &x, &n);

    if (n < 1 || x < 0)
        printf("Error");
    else
    {
        double result = 0;
        while (n > 0)
        {
            result = sqrt(result + x);
            n--;
        }
        printf("%.4lf", result);
    }
    return 0;
}
