#include <stdio.h>

int main()
{
    int n; // number of elements
    scanf("%d", &n);
    if (n < 1)
        printf("Error");
    else
    {
        int sum = 0;
        // init array
        int a[10000];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        // display reverse array
        for (int i = n - 1; i >= 0; i--)
            printf("%d ", a[i]);
        // display sum
        printf("\n%d", sum);
    }
    
    return 0;
}
