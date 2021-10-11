#include<iostream>
#include<iomanip>
#include<math.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{
    int n = 20;
    srand(time(NULL));
    cout << n << " " << rand() % 10 + 10 << endl;
    while (n > 0)
    {
        cout << rand() % (30 - 1 + 1) + 1 << " ";
        n--;
    }   
    return 0;
}