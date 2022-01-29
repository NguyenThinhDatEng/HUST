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
int m;                 // number of teachers 1 <= m <= 10
int n;                 // number of courses 1 <= n <= 30
vector<vector<int>> v; // preference list
int k;                 // the number of pairs of conflicting courses   k <= 900
int conflict[901][901];
vector<vector<int>> teachers; // store the selected coursed
int res = INT_MAX;

void input()
{
    cin >> m >> n;
    // organize vector v
    v.resize(m + 1);
    for (int i = 1; i <= m; i++)
    {
        v[i].resize(n + 1);
    }
    // get data for v
    int tmpSize;
    int tmp;
    for (int i = 1; i <= m; i++)
    {
        cin >> tmpSize;
        for (int j = 0; j < tmpSize; j++)
        {
            cin >> tmp;
            v[i][tmp] = 1;
        }
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // get data for conflict
    cin >> k;
    int i, j;
    while (k-- > 0)
    {
        cin >> i >> j;
        conflict[i][j] = conflict[j][i] = 1;
    }

    // organize teachers
    teachers.resize(m + 1);
}

bool check(int k, int i)
{
    if (v[i][k])
    {
        for (int course : teachers[i])
        {
            if (conflict[k][course])
                return false;
        }
        return true;
    }
    return false;
}

void TRY(int k, int maxLoad)
{
    if (maxLoad >= res)
        return;
    if (k > n)
    {
        res = min(res, maxLoad);
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (check(k, i))
        {
            teachers[i].push_back(k);
            int noOfCourses = teachers[i].size();
            TRY(k + 1, max(maxLoad, noOfCourses));
            teachers[i].pop_back();
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    TRY(1, 0);

    cout << res;

    return 0;
}