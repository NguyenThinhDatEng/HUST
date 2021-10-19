#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int t;
int x[8];   // contain result letters
int existed[8];

void display()
{
    for (int i = 0; i < t; i++)
        cout << (char) (x[i] + 'A');
    cout << endl;
}

void TRY(int k)
{
    for (int i = 0; i < 8 && k < t; i++)
    {
        if (existed[i] == 0)
        {
            x[k] = i;
            existed[i] = 1;
            if (k == t - 1)
                display();
            else
                TRY(k + 1);
            existed[i] = 0;
        }
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < 8; i++)
        existed[i] = 0;
    TRY(0);
    return 0;
}