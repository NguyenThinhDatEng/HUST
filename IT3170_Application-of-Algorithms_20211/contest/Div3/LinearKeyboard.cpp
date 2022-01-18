#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    int t;
    cin >> t;
    string s;
    string word;
    int rs;
    while (t > 0)
    {
        cin >> s;
        cin >> word;
        rs = 0;
        map<char, int> m;
        int i = 0;
        for (char c : s)
        {
            i++;
            m[c] = i;
        }

        int length = word.length() - 1;
        if (length == 0)
        {
            cout << 0 << endl;
            t--;
            continue;
        }

        char a, b;
        for (int i = 0; i < length; i++)
        {
            a = word[i];
            b = word[i + 1];
            rs += abs(m[a] - m[b]);
        }
        
        cout << rs << endl;
        m.clear();
        t--;
    }
    return 0;
}