#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    const int divisor = pow(10, 9) + 7;
    int n;
    cin >> n;
    unsigned long long sum = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp % divisor;
    }
    cout << sum % divisor;
    return 0;
}