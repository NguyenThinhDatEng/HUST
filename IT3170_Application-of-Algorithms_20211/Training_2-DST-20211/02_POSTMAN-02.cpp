#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>

#define ll long long
#define ull unsigned long long

using namespace std;

void input(int &n, int &k, vector<pair<int, int>> &x_negative, vector<pair<int, int>> &x_positive)
{
    cin >> n >> k;
    int x; // |xi| ≤ 10^7   coordinates
    int m; // 1 ≤ mi ≤ 10^7     number of packages to be delivered
    for (int i = 0; i < n; i++)
    {
        cin >> x >> m;
        if (x < 0)
            x_negative.push_back({-x, m});
        else
            x_positive.push_back({x, m});
    }
}

ll solve(int k, vector<pair<int, int>> v)
{
    sort(v.begin(), v.end());
    int x, m;
    int times;    // max = 10^7
    int left = 0; // the number of left packages
    ll rs = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        x = v[i].first;
        m = v[i].second;

        if (left)
        {
            if (left >= m)
            {
                left -= m;
                continue;
            }
            m -= left;
        }

        times = m / k;
        if (m % k)
            times++;
        // highlight
        rs += 1LL * 2 * times * x;
        left = times * k - m;
    }
    return rs;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n; // n ≤ 1000  number of customers
    int k; // k ≤ 10 ^ 7    limited number of packages
    vector<pair<int, int>> x_negative;
    vector<pair<int, int>> x_positive;

    input(n, k, x_negative, x_positive);

    cout << solve(k, x_negative) + solve(k, x_positive);

    return 0;
}
