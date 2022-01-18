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

void input(int &n, vector<int> &v);

ll subSeqMax(int n, vector<int> v);

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n; // n <= 10^6
    vector<int> v;

    input(n, v);

    cout << subSeqMax(n, v);

    return 0;
}

void input(int &n, vector<int> &v)
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}

ll subSeqMax(int n, vector<int> v)
{
    ll maxValue = v[0];
    ll sum = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] < 0)
        {
            sum += v[i];
            maxValue = maxValue > v[i] ? maxValue : v[i];
        }
        else
        {
            if (sum > 0)
            {
                sum += v[i];
                maxValue = max(sum, maxValue);
            }
            else
            {
                if (maxValue < v[i])
                {
                    sum = v[i];
                    maxValue = v[i];
                }
            }
        }
    }
    return maxValue;
}