#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

vector<int> fibo;

void setFibo(int n, int j)
{
    if (n <= 2)
        return;
    if (fibo.size() == n + 1)
        return;
    fibo.push_back(fibo[j] + fibo[j + 1]);
    return setFibo(n, j + 1);
}

char solve(int n, int i)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (i > fibo[n - 2])
        return solve(n - 1, i - fibo[n - 2]);
    else
        return solve(n - 2, i);
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n;
    cin >> n;

    fibo.push_back(1);
    fibo.push_back(1);
    fibo.push_back(1);
    setFibo(n, 1);

    int limit = fibo.back();
    for (int i_th = 1; i_th <= limit; i_th++)
    {
        cout << solve(n, i_th);
    }

    return 0;
}