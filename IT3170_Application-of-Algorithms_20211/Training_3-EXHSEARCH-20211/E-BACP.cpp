#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n; // 2 ≤ n ≤ 16 is number of courses
int m; // 2 ≤ m ≤ 5 is number of periods
int credits[17];
int periods[10];
vector<vector<int>> prerequisites;

int periodSelected[20];
int courseAsPre[20]; // save all of the course as prerequisites

int maxLoad = 0;
int minOf_maxLoad = INT_MAX;

void input()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> credits[i];
    }

    prerequisites.resize(n + 1);
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp;
            if (tmp)
            {
                prerequisites[i].push_back(j);
                courseAsPre[j] = 1;
            }
        }
    }
}

bool check(int k, int i)
{
    if (courseAsPre[k])
        return true;

    // The semester of the prerequisite subject must be smaller than the following subject
    for (int j : prerequisites[k])
    {
        if (i < periodSelected[j])
            return false;
    }
    return true;
}

void TRY(int k)
{
    // course k th will be assigned to i th periods
    for (int i = 1; i <= m; i++)
    {
        if (check(k, i))
        {
            periodSelected[k] = i;
            periods[i] += credits[k];
            int pre = maxLoad;
            maxLoad = max(maxLoad, periods[i]);
            if (k == n)
            {
                minOf_maxLoad = min(minOf_maxLoad, maxLoad);
            }
            else
            {
                if (maxLoad < minOf_maxLoad)
                    TRY(k + 1);
            }
            // backtracking
            periods[i] -= credits[k];
            periodSelected[k] = 0;
            maxLoad = pre;
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    TRY(1);

    cout << minOf_maxLoad;

    return 0;
}