#include <stdio.h>

int main()
{
    // initialize
    int n;
    double x;
    scanf("%d%lf", &n, &x);
    // Algorithm
    if (n <= 0)
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
        printf("%lf", result);
    }
    return 0;
}
