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
int n; // number of passengers 1 <= n <= 11
int k; // number of places in the bus 1 <= k <= 10
int minDis = INT_MAX;
int v[625][625];      // v[i][j] is the distance from point i to point j
int minV = INT_MAX;   // the smallest value in v array
vector<bool> visited; // mark point was visited
vector<bool> onBus;
int size; // loop limit

void input()
{
    cin >> n >> k;
    // memset onBus
    onBus.resize(n + 1);
    fill(onBus.begin(), onBus.end(), false);
    // setup v
    size = 2 * n;
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            cin >> v[i][j];
            if (v[i][j])
                minV = min(v[i][j], minV);
        }
    }
    // setup visited
    visited.resize(size + 1);
    fill(visited.begin(), visited.end(), false);
    // cout << minV << endl;
}

bool check(int i, int seats)
{
    if (visited[i])
        return false;
    if (seats == 0)
    {
        if (i <= n)
            return false;
        if (onBus[i - n])
            return true;
        return false;
    }

    if (i > n && !onBus[i - n])
        return false;

    return true;
}

void TRY(int k, int dis, int pre, int seats)
{
    // seats is the number of seats available on the bus
    if (dis + minV * (size - k + 1) >= minDis)
        return;
    if (k == size)
    {
        dis += v[pre][0];
        minDis = min(minDis, dis);
        return;
    }

    for (int i = 1; i <= size; i++)
    {
        if (check(i, seats))
        {
            // cout << i << " ";
            visited[i] = true;
            if (i <= n)
            {
                onBus[i] = true;
                TRY(k + 1, dis + v[pre][i], i, seats - 1);
            }
            else
            {
                onBus[i - n] = false;
                TRY(k + 1, dis + v[pre][i], i, seats + 1);
            }
            // backtracking
            if (i <= n)
                onBus[i] = false;
            else
                onBus[i - n] = true;
            visited[i] = false;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    TRY(0, 0, 0, k);

    cout << minDis;

    return 0;
}
