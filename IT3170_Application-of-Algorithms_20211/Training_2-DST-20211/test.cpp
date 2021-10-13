#include<iostream>
#include<iomanip>
#include<math.h>
#include<ctime>
using namespace std;

int main()
{
    int t = 10;
    srand(time(NULL));
    while(t > 0)
    {
        cout << rand() % (100000 - 25 + 1) + 1 << endl;
        t--;
    }
    return 0;
}