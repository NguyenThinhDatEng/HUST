#include <stdio.h>

int main()
{
    // init
    int n;
    scanf("%d", &n);
    // algo
    if (n >= 1000)
    {
        printf("ERROR");
        return 0;
    }
    int unit, sum = 0;
    while (n > 0)
    {
        unit = n % 10;
        sum += unit;
        n /= 10;
    }
    // display
    printf("%d", sum);
    return 0;
}
