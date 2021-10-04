/*
CT1: (a+b)%d = ((a%d)+(b%d))%d.

CT2: (a-b)%d = ((a%d)-(b%d))%d.

CT3: (a*b)%d = ((a%d)*(b%d))%d.
*/
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    const int divisor = pow(10, 9) + 7;
    unsigned long long a, b;
    cin >> a >> b;
    cout << ((a % divisor) + (b % divisor)) % divisor;
    return 0;
}
// 9 223 372 036 854 775 807