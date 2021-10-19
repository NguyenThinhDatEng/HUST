#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int**a;
int n, m;

bool isInvalid(int i, int j)
{
    if (i == 0)
    {
        if (a[1][j])
            return true;
        if (j < n - 1 && a[0][j + 1])
            return true;
        return false;   
    }

    if (i == m - 1)
    {
        if (a[m - 2][j] == 1)
            return true;
        if (a[0][j + 1])
            return true;
        return false;
    }

    if (j == 0)
    {
        if (a[i][1])
            return true;
        if (i < m - 1 && a[i + 1][0])
            return true;
        return false;
    }

    if (j == n - 1)
    {
        if (a[i])
    }

    return false;
}

void TRY(int i, int j)
{
    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if ()
        }
}

int main()
{
    int m, n;
    cin >> m >> n;
    a = new int*[m];
    for (int i = 0; i < m; i++)
        a[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    TRY(0, 0);
    return 0;
}