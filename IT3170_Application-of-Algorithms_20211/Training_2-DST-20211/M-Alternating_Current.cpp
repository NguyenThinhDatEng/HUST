#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>
#include <stdio.h>
using namespace std;
// FILE* inp, *out;

void solve(string s)
{
    int i = 0;
    while (s.length() > 2 && i < s.length())
    {
        if (s[i] == s[i + 1])   // ++ or --
        {
            s.erase(i, 2);  // delete
            if (i != 0)
                i--;    // take a index back
        }
        else
            i++;
    }

    if (s.length() == 1)
    {
        cout << "NO";
        return;
    }

    if (s.length() == 2)
    {
        if (s[0] == s[1])   // ++ or --
            cout << "YES";
        else
            cout << "NO";   // +- or -+
        return;
    }

    cout << "NO";
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // inp = freopen("LIS.inp", "r", stdin);
    // out = freopen("sol1.out", "w", stdout);
    // instance variable
    string s; // n is length of s, 1 ≤ n ≤ 100000
    cin >> s;
    
    solve(s);

    return 0;
}