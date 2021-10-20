#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;


int n;                  // n <= 20
int a[21][21];          // contains cost input
int minCost;            // minimum costs when traveling n cities
int existed[21];        // mark the city that traveled
int minC = pow(10,6);   // minimum cost of a[21][21]

void TRY(int k, int i, int cost)
{
    if (cost + minC * (n - k) > minCost)
        return;
    
    if (k == n - 1)
    {
        if (a[i][1])    // exist the road to return 1 city
        {
            minCost = min(minCost, cost + a[i][1]);
            return;
        }
        return;
    }

    // j is the next city
    for (int j = 2; j <= n; j++)
        if (a[i][j] && existed[j] == 0)
        {
            existed[j] = 1;
            TRY(k + 1, j, cost + a[i][j]);
            existed[j] = 0;
        }
}

int main()
{
    cin >> n;
    int m; // m < 400
    cin >> m;
    for (int i = 1; i <= 20; i++)
    {
        existed[i] = 0;
        for (int j = 0; j <= 20; j++)
            a[i][j] = 0;
    }   

    int i, j;       // i,j <= n
    int c;          // c <= 10^6
    int maxC = 0;   // maximum cost of a[21][21]
    while(m > 0)
    {
        cin >> i >> j;
        cin >> c;
        a[i][j] = c;
        maxC = maxC > c ? maxC : c;
        minC = minC > c ? c : minC;

        m--;
    }

    minCost = maxC * n;
    TRY(0, 1, 0);
    cout << minCost;
    return 0;
}