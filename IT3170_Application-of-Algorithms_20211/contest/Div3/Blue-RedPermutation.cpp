#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    vector<int> a;
    vector<int> b;
    vector<vector<int>> c;
    string s;
    while (t > 0)
    {
        cin >> n;

        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }

        cin >> s;

        if (n == 1)
        {
            cout << "yes" << endl;
            a.clear();
            t--;
            continue;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'B')
                b[i] = -1;
            else
                b[i] = 1;
        }

        c.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j] == i)
                    c[i].push_back(j + 1);
                else if (a[j])
            }
        }

        a.clear();
        b.clear();
        c.clear();
        t--;
    }
    return 0;
}