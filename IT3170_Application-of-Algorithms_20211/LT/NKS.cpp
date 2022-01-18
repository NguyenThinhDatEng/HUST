#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

int n;
int K;
int S;
int a[100];
int rs;

void TRY(int t, int sum, int cur)
{
    if (sum + (K - t + 1) * a[cur + 1] > S)
        return;
    if (t > K)
    {
        if (sum == S)
        {
            rs++;
        }
        return;
    }
    for (int i = cur + 1; i <= n - K + t; i++)
    {

        TRY(t + 1, sum + a[i], i);
    }
}

int main()
{
    rs = 0;
    cin >> n >> K >> S;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    TRY(1, 0, 0);

    cout << rs;
    return 0;
}