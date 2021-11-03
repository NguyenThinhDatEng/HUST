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

    set<char> digit;
    for (char c : s)
    {
        digit.insert(c);
    }
    
    if (digit.size() % 2)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}