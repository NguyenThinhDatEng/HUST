#include <stdio.h>
#include <math.h>

int main()
{
    // initialize variables
    int n;
    int is_Prime = 1;
    scanf("%d", &n);
    // algo
    if (n < 2)
        is_Prime = 0;
    else
    {
        int sqr = sqrt(n);
        for (int i = 2; i <= sqr; i++)
            if (n % i == 0)
            {
                is_Prime = 0;
                break;
            }
    }
    // display
    if (is_Prime)
        printf("La so nguyen to");
    else
        printf("Khong phai so nguyen to");
    return 0;
}
