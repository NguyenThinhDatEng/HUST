#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;

int n;
string s;
int res = 0;

bool check(int L, int R)
{
    map<char, int> a;
    for (int i = L; i <= R; i++)
    {
        a[s[i]] += 1;
    }
    int even = 0, odd = 0;
    map<char, int>::iterator it = a.begin();
    for (; it != a.end(); it++)
    {
        if (it->second % 2 == 0)
            even++;
        else
            odd++;
    }
    // cout << L << " " << R << " " << even << " " << odd << endl;
    if ((R - L) % 2 == 0)
    {
        if (odd == 1)
            return true;
    }
    else
    {
        if (odd == 0)
            return true;
    }

    return false;
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (check(i, j))
            {
                res++;
                // cout << res << endl;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    solve();
    cout << res;
    return 0;
}