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
    string s;
    cin >> s;

    input();
    int countUp = 0, countLow = 0;
    for (char c : s)
    {
        if (c <= 'Z' && c >= 'A')
            countUp++;
        else
            countLow++;
    }

    char* c = &s[0];
    if (countUp > countLow)
    {
        strupr(c);
    }
    else
        strlwr(c);

    cout << s;
    return 0;
}