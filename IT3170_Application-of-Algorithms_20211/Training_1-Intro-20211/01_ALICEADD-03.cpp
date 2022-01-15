#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>

#define ll long long           // 9,223,372,036,854,775,807
#define ull unsigned long long // 18,446,744,073,709,551,615

using namespace std;

void input();

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    ull a, b;
    cin >> a >> b;
    // set up
    ull s1, s2; // n*10^18
    s1 = a / 10;
    s2 = b / 10;
    int unitA, unitB;
    unitA = a % 10;
    unitB = b % 10;
    // algorithm
    ull first;
    int second;
    first = s1 + s2;
    second = unitA + unitB;
    if (second >= 10)
    {
        first += 1;
        second -= 10;
    }
    if (first)
        cout << first;
    cout << second;
    return 0;
}

void input()
{
}