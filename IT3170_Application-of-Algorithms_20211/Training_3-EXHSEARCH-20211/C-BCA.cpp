#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

int m;  // teachers 1 ≤ m ≤ 10
int n;  // courses 1 ≤ n ≤ 30
int preferenceList[11][31]; // a list of courses he/she can teach depending on his/her specialization
int pairsOfConflicting[31][31];
vector<vector<int>> teacher;    // trace
int minOf_maxLoad = INT_MAX;
int maxLoad = 0;

bool check(int newCourse, int teacher_name)
{
    // suitable course for each teacher
    if (preferenceList[teacher_name][newCourse] == 0)
        return false;

    // check conflict
    int size = teacher[teacher_name].size();
    int selectedCourse;
    for (int i = 0; i < size; i++)
    {   
        selectedCourse = teacher[teacher_name][i];
        if (pairsOfConflicting[newCourse][selectedCourse] == 1)
        {
            return false;
        }
    }
    return true;
}

void input() {
    cin >> m;
    cin >> n;
    teacher.resize(m + 1);

    int k;  //indicating the courses that teacher i can teach 
    int course_name;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> course_name;
            preferenceList[i][course_name] = 1;
        }
    }

    cin >> k;   // k is number of pairs of conflicting two courses

    int firstCou, secondCou;
    for (int i = 1; i <= k; i++)    
    {
        cin >> firstCou >> secondCou;
        pairsOfConflicting[firstCou][secondCou] = pairsOfConflicting[secondCou][firstCou] = 1;
    }
}

void TRY(int k)
{
    if (k > n)
    {
        minOf_maxLoad = min(maxLoad, minOf_maxLoad);
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (check(k, i))
        {
            teacher[i].push_back(k);    // trace
            int pre_maxLoad = maxLoad;
            int size = teacher[i].size();
            maxLoad = max(size, maxLoad);   // set maxLoad
            if (maxLoad < minOf_maxLoad)    // cut branch
                TRY(k + 1);
            // backtracking
            teacher[i].pop_back();
            maxLoad = pre_maxLoad;            
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);

    input();

    TRY(1);

    cout << minOf_maxLoad;
    return 0;
}