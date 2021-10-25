#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

int main()
{
    int t;  // 1 <= t <= 1000
    cin >> t;
    string s;   // 2 <= |s| <= 100
    getline(cin, s);
    while (t > 0)
    {
        getline(cin, s);
        int length = s.length();
        int index = length - 1;
        char lexicographically = s[index];
        for (int i = length - 2; i >= 0; i--)
        {
            if (s[i] < lexicographically)
            {
                lexicographically = s[i];
                index = i;
            }
        }

        if (index == 0)
            cout << lexicographically << " " << s.substr(1) << endl;
        else
            cout << lexicographically << " " << s.substr(0, index) + s.substr(index + 1) << endl;

        t--;
    }
    return 0;
}