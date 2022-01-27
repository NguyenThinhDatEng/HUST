#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>

#define ll long long
#define ull unsigned long long

using namespace std;

// instance variable
int n;                    // number of objects n <= 30
int b;                    // weight limit b <= 10^6
vector<pair<int, int>> v; // contains a and c
ll maxValue = 0;

void input()
{
    cin >> n >> b;
    int a, c; // an object has weight a and value c <= 10^6
    for (int i = 0; i < n; i++)
    {
        cin >> a >> c;
        v.push_back({a, c});
    }
}

void TRY(int k, int maxWeight, ll value)
{
    if (maxWeight < 0)
        return;
    if (k == n)
    {
        maxValue = max(maxValue, value);
        return;
    }
    // take object k and put it in the bag
    TRY(k + 1, maxWeight - v[k].first, value + v[k].second);
    // don't take object k
    TRY(k + 1, maxWeight, value);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    TRY(0, b, 0);

    cout << maxValue;

    return 0;
}
