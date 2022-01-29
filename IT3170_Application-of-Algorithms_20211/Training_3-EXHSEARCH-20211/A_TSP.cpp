#include <iostream>
#include <vector> // fill
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
int n;           // number of cities <= 20
int m;           // number of lines < 400
int v[500][500]; // v[i][j] is the cost from city i to city j
vector<bool> visited;
int minCost = INT_MAX;

void input()
{
    cin >> n >> m;
    int i, j; // i, j <= n
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        cin >> v[i][j]; // <= 10^6
    }

    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
}

void TRY(int k, int pre, int cost)
{
    if (cost >= minCost)
        return;
    if (k == n)
    {
        int c = v[pre][1];
        if (c)
        {
            minCost = min(minCost, cost + c);
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        int c = v[pre][i];
        if (c && !visited[i])
        {
            visited[i] = true;
            TRY(k + 1, i, cost + c);
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

    TRY(1, 1, 0);

    cout << minCost;

    return 0;
}