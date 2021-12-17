#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<math.h>
#include<iomanip>
#include<set>
using namespace std;

void input(int& n, vector<int>& v);

int maxLeftMid(vector<int>& v, int l, int r)
{
    int maxLM = v[r];
    int sum = v[r];
    for (int i = r - 1; i >= l; i--)
    {
        sum += v[i];
        maxLM = max(maxLM, sum);
    }
    return maxLM;
}

int maxRightMid(vector<int>& v, int l, int r)
{
    int maxRM = v[l];
    int sum = v[l];
    for (int i = l + 1; i <= r; i++)
    {
        sum += v[i];
        maxRM = max(maxRM, sum);
    }
    return maxRM;
}

int subSeqMax(vector<int>& v, int l, int r) {
    if (l == r) return v[l];
    int mid = (l + r) / 2;
    int wL = subSeqMax(v, l, mid);
    int wR = subSeqMax(v, mid + 1, r);
    int maxLM = maxLeftMid(v, l, mid);
    int maxRM = maxRightMid(v, mid + 1, r);
    int wM = maxLM + maxRM;
    return max(max(wL, wR), wM);
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    // instance variable
    int n = 0;
    vector<int> v;

    input(n, v);
    cout << subSeqMax(v, 0, n - 1);

    return 0;
}

void input(int& n, vector<int>& v) {
    cout << "n = ";
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}