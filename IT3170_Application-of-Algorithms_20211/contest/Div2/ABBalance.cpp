#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if (s[0] == 'a')
            if (s[n - 1] == 'b')
                s[n - 1] = 'a';

        if (s[0] == 'b')
            if (s[n - 1] == 'a')
                s[n - 1] = 'b';
        cout << s << '\n';
    }
}