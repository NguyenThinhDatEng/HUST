#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;
using point = pair<int, int>;

vector<int> numberOf_vtcp;
int existedIndex = 0;
int rs;

int binarySearch(vector<point> &VTCP, point p, int l, int r)
{
    int mid;
    if (r >= l)
    {
        mid = (l + r) / 2;
        point element = VTCP[mid];
        if (element == p)
        {
            existedIndex = mid;
            return -1;
        }

        if (element > p)
        {
            return binarySearch(VTCP, p, l, mid - 1);
        }

        if (element < p)
        {
            return binarySearch(VTCP, p, mid + 1, r);
        }
    }
    if (l == mid)
        return mid;
    return l;
}

void solve(vector<point>& VTCP, vector<point>& firstArr, vector<point>& secondArr)
{
    int sizeF = firstArr.size();
    int sizeS = secondArr.size();
    point vtcp;

    for (int i = 0; i < sizeF; i++)
    {
        for (int j = 0; j < sizeS; j++)
        {
            vtcp.first = firstArr[i].first - secondArr[j].first;
            vtcp.second = firstArr[i].second - secondArr[j].second;
            int index = binarySearch(VTCP, vtcp, 0, VTCP.size() - 1);
            if (index == -1)
            {
                numberOf_vtcp[existedIndex]++;
                rs = max(rs, numberOf_vtcp[existedIndex]);
            }
            else
            {
                VTCP.insert(VTCP.begin() + index, 1, vtcp);
                numberOf_vtcp.insert(numberOf_vtcp.begin() + index, 1, 1);
            }
        }       
    }
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
    int L, C; // 1≤L,C≤1000
    vector<point> firstArr, secondArr;
    vector<point> VTCP;
    while (t > 0)
    {
        input(L, C, firstArr, secondArr);

        // prepare to algorithm
        VTCP.push_back({0, 0});
        numberOf_vtcp.resize(1);

        // reset rs
        rs = 0;
        solve(VTCP, firstArr, secondArr);

        cout << rs << endl;

        firstArr.clear();
        secondArr.clear();
        numberOf_vtcp.clear();
        VTCP.clear();
        t--;
    }
    return 0;
}