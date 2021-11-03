#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

void input(int &n, string &s)
{
    cin >> n;
    cin >> s;
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    input(n, s);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            count++;
        else
            count--;
    }

    if (count == 0)
        cout << "Friendship";
    else if (count < 0)
        cout << "Danik";
    else
        cout << "Anton";

    return 0;
}