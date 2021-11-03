#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

void input() {
    int tmp;
    int m, n;
    for (int i = 1; i <= 25; i++)
    {
        cin >> tmp;
        if (tmp)
        {
            if (i % 5)
            {
                m = i / 5 + 1;
                n = i % 5;
            }
            else
            {
                m = i / 5;
                n = 5;
            }
        }
    }
    cout << abs(m - 3) + abs(n - 3);
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);

    input();

    return 0;
}