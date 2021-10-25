#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int m, n;   // teachers, courses
vector<vector<int>> preferenceList;
vector<vector<int>> pairsOfConflicting;
vector<vector<int>> trace;
vector<int> existed;
int course;
int maxLoad;
int minOfMaxLoad = INT_MAX;

void TRY(int k, int previousCourse)
{
    if (k > n)
    {
        minOfMaxLoad = min(minOfMaxLoad, maxLoad);
        return;
    }

    // for (int i = 1; i <= m; i++)
    // {
    //     int size = preferenceList[i].size();
    //     int maxLoad = -1;
    //     int tmpMaxLoad = 0;
    //     for (int j = 0; j < size; j++)
    //     {
    //         course = preferenceList[i][j];
    //         if (existed[course] == 0 && pairsOfConflicting[previousCourse][course] != 1)
    //         {
    //             trace[i].push_back(course);
    //             existed[course] = 1;
    //             tmpMaxLoad++;
    //             TRY(k + 1, course);
    //         }
    //     }
    //     maxLoad = max(maxLoad, tmpMaxLoad);
    // }

}

int main()
{
    cin >> m >> n;  // 1 <= m <= 10, 1 <= n <=30
    preferenceList.resize(m + 1);
    trace.resize(m + 1);
    existed.resize(n + 1);

    int k;  // indicating the courses that teacher i can teach
    int tmp;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        preferenceList[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            preferenceList[i][j] = tmp;
        }
    }

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

    TRY(1, 0);

    cout << 1;
    return 0;
}