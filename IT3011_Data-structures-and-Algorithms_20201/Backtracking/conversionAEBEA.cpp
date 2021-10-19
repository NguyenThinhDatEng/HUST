#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int x[5];

void display()
{
    for (int i = 0; i < 5; i++)
        cout << (char) (x[i] + 'A');
    cout << endl;
}

void TRY(int k, int countA, int countB, int countE)
{
    if (countA < 0 || countB < 0 || countE < 0)
        return;
    if (k == 5)
    {
        display();
        return;
    }

    x[k] = 0;
    TRY(k + 1, countA - 1, countB, countE);
    x[k] = 1;
    TRY(k + 1, countA, countB - 1, countE);
    x[k] = 4;
    TRY(k + 1, countA, countB, countE - 1);
}

int main()
{
    TRY(0, 2, 1, 2);
    return 0;
}