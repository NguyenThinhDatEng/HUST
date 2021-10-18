#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<time.h>
#include<cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int t = rand() % (15 - 5 + 1) + 5;
    cout << t << endl;
    while (t > 0)
    {
        int n = rand() % (15 - 1 + 1) - 1;
        cout << n << " ";
        t--;
    }
    return 0;
}