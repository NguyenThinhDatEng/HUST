#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;

int solve(int n, int b) {
    int* a = new int[n];
    int signalCutOff = 0;
    int maxHead = a[0];
    int maxTail = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxTail = max(maxTail, a[i]);
    }

    for (int i = 1; i < n - 1; i++)
        if (maxHead - a[i] >= b)
        {
            if (maxHead > maxTail || a[i] > maxTail)
            {
                int *pTail = a + i + 1;
                int j = 0;
                maxTail = 0;
                while (j < n)
                {
                    maxTail = max(maxTail, pTail[j]);
                    j++;
                }
            }
            if (maxTail - a[i] >= b)
            {
                int tmp = maxTail + maxHead  - 2 * a[i];
                signalCutOff = max(tmp, signalCutOff);
            }
        }
        else
        {
            maxHead = max(maxHead, a[i]);
        }
    return signalCutOff;
}

int main()
{
    int n;
    cin >> n;
    int b;
    cin >> b;
    cout << solve(n, b);
    return 0;
}