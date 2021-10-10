#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool closing (char p)
{
    if (p == '}' || p == ')' || p == ']')
        return true;
    return false;
}

bool respectively(char p, char q)
{
    if (p == '(' && q == ')')
        return true;
    if (p == '[' && q == ']')
        return true;
    if (q == '{' && q == '}')
        return true;
    return false;
}

int solve(string s)
{
    vector<int> parentheses;
    parentheses.push_back(0);
    parentheses.push_back(0);
    parentheses.push_back(0);
    int length = s.length();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '}')
            if (parentheses[0])
                parentheses[0]--;
            else
                return 0;
        else if (s[i] == ']')
            if (parentheses[1])
                parentheses[1]--;
            else
                return 0;
            else if (s[i] == ')')
                if (parentheses[2])
                    parentheses[2]--;
                else
                    return 0;
        if (s[i] == '{')
            parentheses[0]++;
        else if (s[i] == '[')
            parentheses[1]++;
            else if (s[i] == '(')
                parentheses[2]++;
    }
    if (parentheses[0] + parentheses[1] + parentheses[2])
        return 0;
    return 1;
}

int main()
{
    int T;
    cin >> T;
    string s;
    getline(cin, s);
    while (T > 0)
    {
        getline(cin, s);
        cout << solve(s) << endl;
        T--;
    }
    return 0;
}