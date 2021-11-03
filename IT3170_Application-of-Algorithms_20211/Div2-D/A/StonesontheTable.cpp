#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<set>
using namespace std;

void input() {
    
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    // instance variable
    int n;
    cin >> n;
    string s;
    cin >> s;

    input();
    int i = 0;
    int count = 0;
    for (int j = 1; j < n; j++)
    {
        if (s[j] == s[i])
        {
            count++;
        }
        else
        {
            i = j;
        }
    }

    cout << count;
    return 0;
}