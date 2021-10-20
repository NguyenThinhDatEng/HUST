#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

int* a;
int* c;
int t;
int maxValue = 0;

void TRY(int k, int b, int value)
{
    if (b < 0)
        return;
    if (k == t)
    {
        maxValue = max(maxValue, value);
        return;
    }
    // don't take object k
    TRY(k + 1, b, value);
    // take object k
    TRY(k + 1, b - a[k], value + c[k]);
}

int main()
{
    int b;
    cin >> t;   // t <= 30
    cin >> b;   // b <= 10^6
    a = new int[t]; // a[i] <= 10^6
    c = new int[t]; // c[i] <= 10^6
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> c[i];
    }
    TRY(0, b, 0);
    cout << maxValue;
    return 0;
}