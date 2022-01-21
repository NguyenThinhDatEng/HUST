#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>

#define ll long long
#define ull unsigned long long

using namespace std;
using x_m = pair<int, int>;

void input(int &n, int &k, vector<x_m> &v);

void pretreatment(vector<x_m> v, vector<x_m> &left_0, vector<x_m> &right_0);

ll solve(int n, int k, vector<x_m> v);

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n;         // n <= 10^3
    int k;         // k <= 10^7
    vector<x_m> v; // x <= 10^7, m <= 10^7
    vector<x_m> left_0;
    vector<x_m> right_0;

    input(n, k, v);

    pretreatment(v, left_0, right_0);

    cout << solve(n, k, right_0) + solve(n, k, left_0);

    return 0;
}

void input(int &n, int &k, vector<x_m> &v)
{
    cin >> n >> k;
    int x, m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> m;
        v.push_back({x, m});
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second << " ";
    // }
    // cout << endl;
}

void pretreatment(vector<x_m> v, vector<x_m> &left_0, vector<x_m> &right_0)
{
    sort(v.begin(), v.end());
    int i = 0;
    while (v[i].first < 0 && i < v.size())
    {
        left_0.push_back({-v[i].first, v[i].second});
        i++;
    }
    reverse(left_0.begin(), left_0.end());
    while (i < v.size())
    {
        right_0.push_back({v[i].first, v[i].second});
        i++;
    }
}

ll solve(int n, int k, vector<x_m> v)
{
    int i = v.size() - 1; // last index
    int k1;               // number of packages remaining
    int maxDis = 0;       // the max of distance in a one time
    bool start = true;    // marks the departure from the center
    ll times = 0;         // the number of times to go to a fixed point
    ll time = 0;          // result

    while (i >= 0)
    {
        if (start)
        {
            k1 = k;
            maxDis = v[i].first;     // first ~ distance
            times = v[i].second / k; // second ~ number of packages to be delivered
        }
        if (times == 0)
        {
            if (k1 > v[i].second)
            {
                start = false;  // have not returned to the starting point yet
                k1 -= v[i].second;
                i--;
            }
            else
            {
                start = true;
                v[i].second -= k1;
                time += maxDis * 2; // update time
            }
            continue;
        }
        time += times * maxDis * 2; // update time
        v[i].second -= times * k1;
        start = true;
        if (v[i].second == 0)
        {
            i--;
        }
    }
    if (start == false) // k >= total of all packages to be delivered
        time += maxDis * 2;

    return time;
}