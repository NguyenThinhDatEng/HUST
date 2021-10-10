#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

void solve(string s1, string s2, int n)
{
    for (int i = 1; i < n - 1; i++)
        if (s1[i] == '1' && s2[i] == '1')
        {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    int n;
    string line1;
    string line2;
    while (t > 0)
    {
        cin >> n;
        getline(cin, line1);
        getline(cin, line1);
        getline(cin, line2);
        solve(line1, line2, n);
        t--;
    }  
    return 0;
}