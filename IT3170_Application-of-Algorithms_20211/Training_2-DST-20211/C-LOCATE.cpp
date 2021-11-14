#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;
using point = pair<int, int>;

int rs;

void solve(vector<point> &firstArr, vector<point> &secondArr)
{
    // initialize VTCP
    vector<vector<int>> VTCP;
    VTCP.resize(2000); // x is the coordinates of vtcp, x belongs to [-999, 999]
    for (int i = 0; i < 2000; i++)
        VTCP[i].resize(2000); // y is the juxtaposition of vtcp, y belongs to [-999, 999]

    int sizeF = firstArr.size();
    int sizeS = secondArr.size();
    int x, y;
    for (int i = 0; i < sizeF; i++)
    {
        for (int j = 0; j < sizeS; j++)
        {
            x = firstArr[i].first - secondArr[j].first + 999;   // x >= 0
            y = firstArr[i].second - secondArr[j].second + 999; // y >= 0
            VTCP[x][y]++;
            rs = max(VTCP[x][y], rs);
        }
    }
    VTCP.clear();
}

void input(int &L, int &C, vector<point> &firstArr, vector<point> &secondArr)
{
    // L is No. of lines
    // C is No. of columns
    cin >> L >> C;

    int binary;
    // input data for first array
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> binary;
            if (binary)
            {
                firstArr.push_back({i, j});
            }
        }

    // input data for second array
    for (int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> binary;
            if (binary)
            {
                secondArr.push_back({i, j});
            }
        }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; // No. of test cases
    cin >> t;
    int L, C; // 1 <= L, C <= 1000

    vector<point> firstArr, secondArr;
    while (t > 0)
    {
        input(L, C, firstArr, secondArr);

        // reset rs
        rs = 0;
        solve(firstArr, secondArr);

        cout << rs << endl;
        // reset vector
        firstArr.clear();
        secondArr.clear();
        t--;
    }
    return 0;
}