#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 8 || n < 0)
        printf("ERROR");
    else
    {
        int factorial = 1;
        for (int i = 2; i <= n; i++)
            factorial = factorial * i;
        printf("%d", factorial);
    }
    return 0;
}
