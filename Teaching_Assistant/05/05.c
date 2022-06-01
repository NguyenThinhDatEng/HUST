#include <stdio.h>

int main()
{
    int n; // number of elements
    scanf("%d", &n);
    // check condition (1 <= n <= 10)
    if (n == 1)
        printf("0");
    else if (n < 1 || n > 10)
        printf("Error");
    else
    {
        // init array
        int a[10];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        // find
        int max_sum = a[0] + a[1];
        for (int i = 2; i < n; i++)
            if (a[i - 1] + a[i] > max_sum)
                max_sum = a[i - 1] + a[i];
        // display the max of multiple
        if (max_sum > 0)
            printf("%d", max_sum);
        else
            printf("0");
    }
    return 0;
}
