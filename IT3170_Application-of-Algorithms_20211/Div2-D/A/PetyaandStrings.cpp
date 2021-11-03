#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

void input(string& s1, string& s2) {
    cin >> s1 >> s2;
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    // instance variable
    string s1, s2;

    input(s1, s2);

    char* c = &s1[0];
    strlwr(c);
    c = &s2[0];
    strlwr(c);
    
    cout << s1.compare(s2);

    return 0;
}