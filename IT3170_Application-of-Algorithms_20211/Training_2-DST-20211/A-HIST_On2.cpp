#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
using namespace std;

long long bestSquare(int* a, int n)
{
    long long maxS = 0;
    for (int l = 0; l < n; l++)
    {
        int minHeight = a[l];
        long long maxL = a[l];
        long long maxTmp = a[l];
        int length = 1;
        for (int r = l + 1; r < n; r++)
        {
            if (minHeight > a[r])
                minHeight = a[r];
            maxTmp = 1LL * minHeight * ++length;
            if (maxL < maxTmp)
                maxL = maxTmp;
        }
        if (maxS < maxL)
            maxS = maxL;
    }
    return maxS;
}

int main()
{
    int n = 1;
    int* a;
    do
    {
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n != 0)
        {
            cout << bestSquare(a, n) << endl;
        }
    } while (n != 0);
    return 0;
}