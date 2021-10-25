#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int t; // 1 ≤ t ≤ 10^4
    cin >> t;
    int a, b, c; //  0 ≤ a, b, c ≤ 10^9
    int maxE;
    while(t > 0)
    {
        maxE = 1;
        cin >> a >> b >> c;
        if (a == b && b == c)
        {
            cout << 1 << " " << 1 << " " << 1 << endl;
            t--;
            continue;
        }

        maxE = max(a, b);
        maxE = max(maxE, c);
        if (a == b && b == maxE)
        {
            cout << 1 << " " << 1 << " " << maxE - c + 1 << endl;
            t--;
            continue;
        }

        if (a == c && c == maxE)
        {
            cout << 1 << " " << maxE - b + 1 << " " << 1 << endl;
            t--;
            continue;
        }

        if (b == c && c == maxE)
        {
            cout << maxE - a + 1 << " " << 1 << " " << 1 << endl;
            t--;
            continue;
        }

        if (a < maxE)
            cout << maxE - a + 1 << " ";
        else
            cout << 0 << " ";
        if (b < maxE)
            cout << maxE - b + 1 << " ";
        else
            cout << 0 << " ";
        if (c < maxE)
            cout << maxE - c + 1 << endl;
        else
            cout << 0 << endl;
        t--;
    }
    return 0;
}