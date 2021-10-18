#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include<math.h>
using namespace std;
using customer = pair<int, int>;

unsigned long long bestTime(vector<customer> v, int k)
{
    // compare to first of pair
    sort(v.begin(), v.end());
    unsigned long long time = 0;
    int x;
    int m;
    int remainingParces = 0;
    int times = 0;
    while (!v.empty())
    {
        x = v.back().first;
        m = v.back().second;

        if (remainingParces != 0)
        {
            if (remainingParces >= m)
            {
                remainingParces -= m;
                v.pop_back();
                continue;
            }
            else
                m -= remainingParces;
        }
        times = m / k;
        if (m % k) times++;
        time += 1ULL * 2 * x * times;
        v.pop_back();   
        remainingParces = times * k - m;
    }
    return time;
}

int main()
{
    vector<customer> cusList_negative;
    vector<customer> cusList_positive;
    int n;
    int k;
    cin >> n >> k;

    int x, m;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> m;
        if (x < 0)
            cusList_negative.push_back({-x, m});
        else
            cusList_positive.push_back({x, m});
    }

    cout << bestTime(cusList_positive, k) + bestTime(cusList_negative, k);

    return 0;
}