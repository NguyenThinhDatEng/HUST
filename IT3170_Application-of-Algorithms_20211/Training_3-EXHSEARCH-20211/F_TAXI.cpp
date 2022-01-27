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
int minDis = INT_MAX;
int v[625][625];      // v[i][j] is the distance from point i to point j
vector<bool> visited; // mark point was visited

void input()
{
    cin >> n;
    // setup visited
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    // setup v
    int size = 2 * n;
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            cin >> v[i][j];
        }
    }
}

void TRY(int k, int dis, int pre)
{
    if (dis > minDis)
        return;
    if (k == n)
    {
        dis += v[pre][0];
        minDis = min(minDis, dis);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            TRY(k + 1, dis + v[pre][i] + v[i][i + n], i + n);
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

    TRY(0, 0, 0);

    cout << minDis;

    return 0;
}
