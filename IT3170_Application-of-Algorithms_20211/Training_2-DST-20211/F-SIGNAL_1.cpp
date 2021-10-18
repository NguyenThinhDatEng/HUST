#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b;
    cin >> b;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> L, R;
    L.resize(n);
    R.resize(n);
    L[0] = a[0];
    R[n - 1] = a[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        L[i] = max(a[i], a[i - 1]);
        R[n - 1 - i] = max(a[n - 1 - i], a[n - i]);
    }

    int signal = -1;
    for(int i = 1; i < n - 1; i++)
        if (L[i - 1] - a[i] >= b && R[i + 1] - a[i] >= b)
            signal = max(L[i - 1] + R[i + 1] - 2 * a[i], signal);
    cout << signal;
    return 0;
}