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
int firstIndex = 0;
int ans;

void input();

auto sum(int H)
{
    long long woodAmount = 0;
    for (int i = firstIndex; i < n; i++)
    {
        woodAmount += v[i] - H;
    }
    return woodAmount;
}

void solve(int minH, int maxH)
{
    if (minH <= maxH)
    {
        int H = (minH + maxH) / 2;
        while (v[firstIndex] <= H)
        {
            firstIndex++;
        }
        auto woodAmount = sum(H);
        if (woodAmount >= M)
        {
            ans = H;
            return solve(H + 1, maxH);
        }
        firstIndex = 0;
        return solve(minH, H - 1);
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
    sort(v.begin(), v.end());
    solve(0, v[n - 1]);
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
    }
}