#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;
int n;         //  1≤N≤1000000
int M;         // 1≤M≤2 000 000 000
vector<int> v; // 1 <= v[i] <= 1e9
int top = 0;
int ans;

void input();

auto check_H(int H)
{
    long long woodAmount = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > H)
            woodAmount += v[i] - H;
    }

    return woodAmount >= M;
}

void solve(int minH, int maxH)
{
    if (minH <= maxH)
    {
        int H = (minH + maxH) / 2;
        if (check_H(H))
        {
            ans = H;
            solve(H + 1, maxH);
        }
        else
            solve(minH, H - 1);
    }
    return;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable

    input();
    solve(0, top);
    cout << ans;
    return 0;
}

void input()
{
    cin >> n >> M;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        top = max(top, tmp);
    }
}