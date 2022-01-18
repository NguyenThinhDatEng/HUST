#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<set>
using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a;
    cin >> b;
    if (b % 2 == 0 && a % 2 == 0)
        c = (b - a) / 2 + 1;
    else if (a % 2 != 0 && b % 2 != 0)
        c = (b - 2 - a) / 2 + 1;
    else
        c = (b - 1 - a) / 2 + 1;
    cout << c;
}