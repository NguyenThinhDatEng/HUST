#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

void input(int& n, vector<int>& v) {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    
    int n;
    vector<int> v;

    input(n, v);
    
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}