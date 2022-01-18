#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int a, b, c;
    while (t > 0)
    {
        cin >> a >> b >> c;
        if ((a + c - 2 * b) % 3)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        t--;
    }
    return 0;
}