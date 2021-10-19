#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int x[5];
int existed[5];

void display()
{
    for (int i = 0; i < 5; i++)
        cout << (char) (x[i] + 'A');
    cout << endl;
}

void TRY(int k)
{
    for (int i = 0; i < 5; i++)
    {
        if (existed[i] == 0)
        {
            x[k] = i;
            existed[i] = 1;
            if (k == 4)
                display();
            else
                TRY(k + 1);
            existed[i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
        existed[i] = 0;
    TRY(0);
    return 0;
}