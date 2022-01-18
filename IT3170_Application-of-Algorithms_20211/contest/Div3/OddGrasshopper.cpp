#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    long long x;
    long long n;
    while (t > 0)
    {
        cin >> x >> n;
        if (x % 2 == 0)
        {
            if (n % 4 == 0)
            {
                cout << x << endl;
            }
            else if (n % 4 == 1)
            {
                cout << x - n / 4 * 4 - 1 << endl;
            }
            else if (n % 4 == 2)
            {
                cout << x + 1 << endl;
            }
            else
                cout << x + (n / 4 + 1) * 4 << endl;
        }
        else
        {
            if (n % 4 == 0)
            {
                cout << x << endl;
            }
            else if (n % 4 == 1)
            {
                cout << x + n / 4 * 4 + 1 << endl;
            }
            else if (n % 4 == 2)
            {
                cout << x - 1 << endl;
            }
            else
                cout << x - (n / 4 + 1) * 4 << endl;
        }
        t--;
    }
    return 0;
}