#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int* x;
int n;

void display()
{
    for (int i = 0; i < n; i++)
        cout << x[i] + 1 << " ";
    cout << endl;
}

bool isInvalid(int i, int j)
{
    for (int k = 0; k < j; k++)
    {
        if (x[k] == i)
            return false;
        if (k - x[k] == j - i)
            return false;
        if (k + x[k] == i + j)
            return false;
    }
    return true;
}

void TRY(int j){
    for (int i = 0; i < n; i++)
    {
        if (isInvalid(i, j))
        {
            x[j] = i;
            if (j == n - 1)
                display();
            else
                TRY(j + 1);
            x[j] = -1;
        }    
    }
}

int main()
{
    cin >> n;
    x = new int[n];
    TRY(0);
    return 0;
}