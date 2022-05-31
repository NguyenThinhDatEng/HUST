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
        int factorial = 1, i = 1;
        double result = 1, numerator = 1;
        
        while (i <= n)
        {
            factorial *= i;
            numerator *= x;
            result += numerator / factorial;
            // printf("%d %lf\n", factorial, x);
            i++;
        }
        printf("%.4lf", result);
    }
    return 0;
}
