#include <stdio.h>

int main()
{
    // initialize
    double x;
    int n;
    scanf("%lf%d", &x, &n);
    // Algorithm
    if (n < 1 || x < 0)
        printf("Error");
    else
    {
        // Initialize new variables
        int i = 1;
        double result = 1, numerator = 1;

        while (i <= n)
        {
            numerator *= x;
            result += numerator / i;
            // printf("%d %lf\n", i, x);
            i++;
        }
        printf("%.4lf", result);
    }
    return 0;
}
