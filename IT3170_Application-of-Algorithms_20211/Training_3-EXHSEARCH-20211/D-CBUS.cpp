#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <deque>
using namespace std;

int n; // 1 ≤ n ≤ 11
int k; // 1 ≤ k ≤ 10
int _2nPlus1;
vector<vector<int>> c; // distance
vector<int> trace;
int existed[23];      // mark the local visited
int bus[12];          // mark the passengers is on bus
int minDis = INT_MAX; // result
int minC = INT_MAX;   // minimum cost of c

void input();

void display();

bool check(int nextLocal, int passengersOnBus)
{
    // Ex n = 3, k = 2
    if (existed[nextLocal])
        return false;

    if (nextLocal > n)
    {
        if (passengersOnBus == 0) // 1 4 5 -> wrong
            return false;
        if (bus[nextLocal - n] == 1) // nextLocal - n => passenger
            return true;
        return false;
    }

    if (passengersOnBus == k && nextLocal <= n) // 1 2 3 -> wrong
    {
        return false;
    }

    return true; // except for all the above cases
}

void TRY(int t, int preLocal, int distance, int passengersOnBus)
{
    if (distance + minC * (_2nPlus1 - t + 1) > minDis)
        return;

    if (t == _2nPlus1)
    {
        // display();
        minDis = min(minDis, distance + c[preLocal][0]);
        return;
    }

    for (int j = 1; j < _2nPlus1; j++)
        if (check(j, passengersOnBus))
        {
            existed[j] = 1;
            trace.push_back(j);
            if (j <= n)
            {
                // trace.push_back(j);
                bus[j] = 1;
                TRY(t + 1, j, distance + c[preLocal][j], passengersOnBus + 1);
            }
            else
            {
                bus[j - n] = 0;
                TRY(t + 1, j, distance + c[preLocal][j], passengersOnBus - 1);
            }
            // backtracking
            trace.pop_back();
            existed[j] = 0;
            if (j <= n)
                bus[j] = 0;
            else
                bus[j - n] = 1;
        }
}

int main()
{
    input();

    TRY(1, 0, 0, 0);

    cout << minDis;
    return 0;
}

void input()
{
    cin >> n;
    cin >> k;
    _2nPlus1 = 2 * n + 1;
    c.resize(_2nPlus1);

    int distance;
    for (int i = 0; i < _2nPlus1; i++)
    {
        c[i].resize(_2nPlus1);
        for (int j = 0; j < _2nPlus1; j++)
        {
            cin >> distance;
            c[i][j] = distance;
            if (distance)
                minC = min(distance, minC);
        }
    }
}

void display()
{
    cout << endl;
    for (int i = 0; i < _2nPlus1 - 1; i++)
    {
        cout << trace[i] << " ";
    }
    cout << endl;
}