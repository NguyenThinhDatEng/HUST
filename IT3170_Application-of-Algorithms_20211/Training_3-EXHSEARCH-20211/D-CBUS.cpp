#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<deque>
using namespace std;

int n;  // 1 ≤ n ≤ 11
int k;  // 1 ≤ k ≤ 10
int _2nPlus1;
vector<vector<int>> c;  // distance 
vector<int> trace;
int existed[23];    // mark the local visited
int bus[12];        // mark passenger is on bus
int minDis = INT_MAX;
int minC = INT_MAX;

void input();

void display();

bool check(int nextLocal, int passengersOnBus)
{
    if (existed[nextLocal])
        return false;

    if (passengersOnBus == 0)
        if (nextLocal <= n)
            return true;
        else
            return false;

    if (passengersOnBus == k)
    {
        if (nextLocal <= n)
            return false;
        for (int i = 1; i <= n; i++)
        {
            if (bus[i] == 1)
            {
                if (nextLocal == i + n)
                {
                    return true;
                }
            }
        }
        return false;
    }

     for (int i = 1; i <= n; i++)
    {
        if (bus[i] == 1)
        {
            if (nextLocal == i + n)
            {
                return true;
            }
        }
        if (nextLocal <= n)
        {
            return true;
        }
    }
    return false;
}

void TRY(int t, int preLocal, int distance, int passengersOnBus)
{
    if (distance + minC * (_2nPlus1 - t + 1) > minDis)
        return;
    
    if (t == _2nPlus1)
    {
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

void input() {
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