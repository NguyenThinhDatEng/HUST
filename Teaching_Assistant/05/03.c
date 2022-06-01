#include <stdio.h>

int main()
{
    int n; // number of elements
    scanf("%d", &n);
    if (n < 1)
        printf("Error");
    else
    {
        // init array
        int a[10000];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        // selection sort
        int tmp;
        for (int i = n - 1; i > 0; i--)
            for (int j = i - 1; j >= 0; j--)
                if (a[i] < a[j])
                {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
        // display sorted array
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
    }
    return 0;
}
