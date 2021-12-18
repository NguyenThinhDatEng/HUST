#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;
using point = pair<int, int>;
using indexPoint = pair<point, int>;

int n; // 2≤N≤50000
double minDistance = 1e+7;
double lineLandmark = 0; // this is the line x = a

point pairIndices;

void input(int &n, vector<indexPoint> &v);

inline void upd_ans(const point a, const point b, const int beforeInd, const int afterInd)
{
    double dist = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    if (dist < minDistance)
    {
        minDistance = dist;                  // update value
        pairIndices = {beforeInd, afterInd}; // update index
    }
}

void checkMidDis(vector<indexPoint> &v, int l, int mid, int r)
{
    vector<point> leftPoint; // contains the points to the left lineLandmark
    vector<point> rightPoint;
    // contains the index of the points while at v
    vector<int> indexLeft;
    vector<int> indexRight;
    lineLandmark = v[mid].first.first;

    for (int i = l; i <= r; i++)
    {
        if (abs(v[i].first.first - lineLandmark) < minDistance) // |x - a| < D
        {
            if (v[i].first.first - lineLandmark <= 0) // put to the left
            {
                leftPoint.push_back(v[i].first);
                indexLeft.push_back(i);
            }
            else
            {
                rightPoint.push_back(v[i].first);
                indexRight.push_back(i);
            }
        }
    }

    int lenOfLeft = leftPoint.size();
    int lenOfRight = rightPoint.size();
    // start checking
    for (int i = 0; i < lenOfLeft; i++)
        for (int j = 0; j < lenOfRight; j++)
            upd_ans(leftPoint[i], rightPoint[j], indexLeft[i], indexRight[j]);
}

void closestPair(vector<indexPoint> &v, int l, int r)
{
    if (l == r) // only have a point
        return;
    if (l == r - 1)
    {
        upd_ans(v[l].first, v[r].first, l, r);
        return;
    }

    int mid = (l + r) / 2;
    closestPair(v, l, mid);
    closestPair(v, mid + 1, r);
    checkMidDis(v, l, mid, r);
}

int main()
{
    // setup
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);
    // instance variable
    vector<indexPoint> v; // contains a point and it's index

    input(n, v);
    sort(v.begin(), v.end()); // a part of algorithms
    closestPair(v, 0, n - 1);

    // get the index of the 2 points found
    int a = v[pairIndices.first].second;
    int b = v[pairIndices.second].second;
    // condition: a < b
    if (a < b)
        cout << a << " " << b << " " << minDistance << endl;
    else
        cout << b << " " << a << " " << minDistance << endl;
    return 0;
}

void input(int &n, vector<indexPoint> &v)
{
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back({{x, y}, i});
    }
}