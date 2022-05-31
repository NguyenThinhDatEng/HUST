#include <stdio.h>

int main()
{
    int a, b; // given variables
    scanf("%d%d", &a, &b);
    // algo
    if (a <= 0 || b <= 0)
    {
        printf("ERROR");
        return 0;
    }
    int A = a, B = b; // the copies
    int UCLN, BCNN;   // results
    // calculate UCLN
    while (A && B)
    {
        if (A > B)
            A %= B;
        else
            B %= A;
    }
    // calculate BCNN
    if (A == 0)
        UCLN = B;
    else
        UCLN = A;
    BCNN = a * b / UCLN;
    printf("%d\n%d", UCLN, BCNN);
    return 0;
}
