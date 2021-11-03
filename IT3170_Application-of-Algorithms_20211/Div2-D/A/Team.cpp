#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

void input(int& n) {
    cin >> n;
}

int main()
{
    int n;
    input(n);
    int a, b, c;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        if (a + b + c >= 2)
            count++;
    }

    cout << count;
    return 0;
}