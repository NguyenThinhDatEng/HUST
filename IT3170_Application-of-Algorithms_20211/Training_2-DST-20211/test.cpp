#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{
    int n = 10;
    srand(time(NULL));
    cout << n << endl;
    while (n > 0)
    {
        cout << rand() % (10 - 1 + 1) + 1 << " ";
        n--;
    }
    cout << endl;
    int t = 10;
    cout << t << endl;
    while (t > 0)
    {
        cout << rand() % (10 - 1 + 1) + 1 << " " << rand() % (10 - 1 + 1) + 1 << endl;
        t--;
    }
    return 0;
}