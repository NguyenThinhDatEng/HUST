#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)

using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    int x = 1;
    int ans = 0;
    while (x < n && x <= k)
    {
        ans++;
        x <<= 1;
    }
    if (x >= n)
    {
        cout << ans << '\n';
    }
    else
    {
        ans += (n - x - 1) / k + 1;
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, h;
    cin >> n >> h;
    int c = 0;
    FOR(i, n)
    {
        int a;
        cin >> a;
        if (a > h)
            c += 2;
        else
            ++c;
    }
    cout << c << '\n';
}