#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int n;
int* x;

void display()
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void TRY(int k, int value)
{
    if (k > n)
    {
        display();
        return;
    }

    x[k] = 0;
    TRY(k + 1, 0);
    if (x[k - 1] != 1)
    {
        x[k] = 1;
        TRY(k + 1, 1);
    }
}

int main()
{
    cin >> n;
    x = new int[n + 1];
    x[0] = 0;
    TRY(1, 0);
    return 0;
}