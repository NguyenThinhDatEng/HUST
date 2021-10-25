#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int n;  // 1 <= n <= 11
int _2nplus1; // 2 * n + 1;
int c[24][24];  // cost
int existed[23];    // mark the city visited
int* trace;
int minDis;         // result
int minC = INT_MAX;

void TRY(int k, int i, int distance)
{
    // _2nplus1 - k + 1 is number of remaining road segments
    if (distance + minC * (_2nplus1 - k + 1) > minDis)
        return;
    
    if (k == _2nplus1)
    {
        minDis = min(minDis, distance + c[i][0]);
        return;
    }

    for (int j = 1; j <= n; j++)
        if (existed[j] == 0)
        {
            trace[k] = j;
            trace[k + 1] = j + n;
            existed[j] = 1;
            TRY(k + 2, j + n, distance + c[i][j] + c[j][j + n]);
            existed[j] = 0;
        }
}

int main()
{
    cin >> n;
    _2nplus1 = 2 * n + 1;
    trace = new int[_2nplus1];
    
    int maxC = 0;
    for (int i = 0; i < _2nplus1; i++)
        for (int j = 0; j < _2nplus1; j++)
        {
            cin >> c[i][j];
            maxC = max(maxC, c[i][j]);
            if (i != j)
                minC = min(minC, c[i][j]);
        }
    minDis = maxC * _2nplus1;
    
    for (int i = 1; i < _2nplus1; i++)
    {
        existed[i] = 0;
    }

    TRY(1, 0, 0);

    cout << minDis;
    return 0;
}