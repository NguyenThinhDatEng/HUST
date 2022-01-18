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

// f[i + 1] = max(a[i], a[i] + f[i]);
int subSeqMax(int n, vector<int> v);

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

int subSeqMax(int n, vector<int> v)
{
    int maxValue = v[0];
    vector<int> f;
    f.resize(1000);
    f[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        f[i] = max(v[i], v[i] + f[i - 1]);
        maxValue = max(maxValue, f[i]);
    }
    return maxValue;
}