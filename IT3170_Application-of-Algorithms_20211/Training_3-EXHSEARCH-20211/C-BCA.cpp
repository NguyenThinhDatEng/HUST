#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;

int m, n;   // teachers, courses
vector<vector<int>> preferenceList;
vector<vector<int>> pairsOfConflicting;
vector<vector<int>> trace;
vector<int> existed;
int tmp;
int maxLoad = 0;
int minOfMaxLoad = INT_MAX;
int sizeTrace;
bool check;

void TRY(int k)
{
    if (k > n)
    {
        // display the courses of each teacher
        // int i = 0;
        // for (int i = 1; i < trace.size(); i++)
        // {
        //     cout << i << ": ";
        //     for (int j = 0; j < trace[i].size(); j++)
        //     {
        //         cout << trace[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        int size;
        for (vector<int> v : trace)
        {
            size = v.size();
            maxLoad = max(maxLoad, size);
        }
        minOfMaxLoad = min(minOfMaxLoad, maxLoad);
        return;
    }

    if (existed[k])
    {
        TRY(k + 1);
    }

    {
        for (int i = 0; i < preferenceList[k].size(); i++)
        {
            check = true;
            tmp = preferenceList[k][i]; // teacher
            sizeTrace = trace[tmp].size();
            for (int j = 0; j < sizeTrace; j++)
            {
                if (pairsOfConflicting.at(trace[tmp][j]).at(k) == 1)
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                trace[tmp].push_back(k);
                TRY(k + 1);
                trace[tmp].pop_back();
            }
        }
    }

}

int main()
{
    cin >> m >> n;  // 1 <= m <= 10, 1 <= n <= 30
    preferenceList.resize(n + 1);   // course -> teachers: 1 -> Van, Lisa
    trace.resize(m + 1);            // teacher -> courses: Van -> 1, 3, 4
    existed.resize(n + 1);          // mark courses that are only suitable for one teacher

    // input
    int k;  // indicating the courses that teacher i can teach
    int teacher;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> teacher;
            preferenceList[teacher].push_back(i);
        }
    }

    // input
    cin >> k;   // number of pairs of conflicting two courses

    pairsOfConflicting.resize(n + 1);
    for (int i = 0; i <= n; i++)
        pairsOfConflicting[i].resize(n + 1);

    int i, j;
    while (k > 0)
    {
        cin >> i >> j;
        pairsOfConflicting[i][j] = pairsOfConflicting[j][i] = 1;
        k--;
    }

    // check courses that are only suitable for one teacher
    for (int i = 1; i <= n; i++)
    {
        if (preferenceList[i].size() == 1)
        {
            teacher = preferenceList[i].back();
            for (int j = 0; j < trace[teacher].size(); j++)
            {
                if (pairsOfConflicting.at(trace[teacher][j]).at(i) == 1)
                {
                    cout << -1;
                    return 0;
                }
            }
            
            existed[i] = 1;
            trace[teacher].push_back(i);
        }
    }

    TRY(1);
    if (maxLoad == 0)
        cout << -1;
    else
        cout << minOfMaxLoad;
    return 0;
}