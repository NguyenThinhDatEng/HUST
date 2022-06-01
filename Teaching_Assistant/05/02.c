#include <stdio.h>

int main()
{
    int n; // number of elements
    scanf("%d", &n);
    if (n < 1)
        printf("Error");
    else
    {
        int numberOfNeg = 0;
        double neg_ave = 0, sum = 0;
        // init array
        int a[10000];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] < 0)
            {
                numberOfNeg++;
                neg_ave += a[i];
            }
            else
                sum += a[i];
        }
        // display negative average
        if (numberOfNeg)
            printf("%lf ", neg_ave / numberOfNeg);
        else
            printf("Mang khong co so am ");
        // display the sum of positive numbers
        if (sum)
            printf("%lf", sum);
        else
            printf("Mang khong co so duong");
    }
    return 0;
}
