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
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void TRY(int k, int value)
{
    if (k == n)
    {
        display();
        return;
    }
    
    x[k] = 0;
    TRY(k + 1, 0);
    x[k] = 1;
    TRY(k + 1, 1);
}

int main()
{
    cin >> n;
    x = new int[n];
    TRY(0, 0);
    return 0;
}