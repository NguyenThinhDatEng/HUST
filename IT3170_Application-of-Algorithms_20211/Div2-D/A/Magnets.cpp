#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

void input(int &n, vector<int> &v)
{
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp / 10);
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n;
    vector<int> v;

    input(n, v);

    int rs = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
            rs++;
    }

    cout << rs;
    return 0;
}