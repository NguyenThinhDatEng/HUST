#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int supSeqMax(int* a, int& n) {
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int currentTotal = a[0];
    int maxTotal = a[0];
    for (int i = 1; i < n; i++)
    {
        if (currentTotal < 0)
            currentTotal = a[i];
        else
        {
            currentTotal += a[i];
            maxTotal = max(maxTotal, currentTotal);
        }
    }
    return maxTotal;
}

int main()
{
    int n;
    int* a;
    cout << supSeqMax(a, n);
    return 0;
}