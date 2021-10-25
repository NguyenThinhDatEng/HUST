#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void display(int binary)
{
    if (binary == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

bool filter(vector<int> a, vector<int> b, int n)
{
    int aSize = a.size();
    int bSize = b.size();
    int i = 0, j = 0;
    int coincide = 0;
    
    for (int i = 0; i < aSize; i++)
            for (int j = 0; j < bSize && a[i] >= b[j]; j++)
                if (a[i] == b[j])
                    coincide++;
    if (bSize + aSize - coincide < n)
        return false;
    return true;
}

void solve(int n, vector<vector<int>> days)
{
    vector<int> v;
    int halfN = n / 2;
    for (int i = 0; i < 5; i++)
        if (days[i].size() >= halfN)
            v.push_back(i);
    if (v.size() < 2)
    {
        display(0);
        return;
    }

    int check = 0;
    int size = v.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (days[v[i]].size() < days[v[j]].size())
            {
                if (filter(days[v[i]], days[v[j]], n))
                {
                    check = 1;
                    break;
                }
            }
            else
                if (filter(days[v[j]], days[v[i]], n))
                {
                    check = 1;
                    break;
                }
    }
    if (check)
        display(1);
    else
        display(0);
}

int main()
{
    int t;
    cin >> t;
    int n;
    while (t > 0)
    {
        int binary;
        cin >> n;
        vector<vector<int>> days(5);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
            {
                cin >> binary;
                if (binary == 1)
                    days[j].push_back(i);
            }
        solve(n, days);
        t--;
    }
    return 0;
}