#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n;
    vector<int> a;
    int tmp;
    bool check = 1;
    while (t > 0)
    {
        cin >> n;
        check = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }

        for (int i = 0; i < n && check; i++)
        {
            if (a[i] % (i + 2) == 0)
            {
                check = 0;
                int j = i + 1;
                while (j >= 2)
                {
                    if (a[i] % j != 0)
                    {
                        check = 1;
                        break;
                    }
                    j--;
                }
            }
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        a.clear();
        t--;
    }
    return 0;
}