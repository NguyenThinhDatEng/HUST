#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    int t;
    cin >> t;
    int n;
    int tmp;
    int preTmp;
    bool check;
    while (t > 0)
    {
        cin >> n;
        check = false;
        cin >> preTmp;
        for (int i = 2; i <= n; i++)
        {
            cin >> tmp;
            if (preTmp >= tmp)
            {
                check = true;
            }
            preTmp = tmp;
        }

        if (n % 2 == 0)
            cout << "YES" << endl;
        else
        {
            if (check)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
        t--;
    }
    return 0;
}