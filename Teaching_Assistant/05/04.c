#include <stdio.h>

int main()
{
    int n; // number of elements
    scanf("%d", &n);
    // check condition (1 <= n <= 10)
    if (n == 1)
        printf("0");
    else
    {
        // init array
        int a[10];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        // find
        int max_multi = 0;
        for (int i = 1; i < n; i++)
            if (a[i - 1] * a[i] > max_multi)
                max_multi = a[i - 1] * a[i];
        // display the max of multiple
        printf("%d", max_multi);
    }
    return 0;
}
