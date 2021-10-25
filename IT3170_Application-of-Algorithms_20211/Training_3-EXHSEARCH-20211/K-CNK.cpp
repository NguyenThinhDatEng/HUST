#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

long long m;    // m <= 10^7 + 9
long long aToThePowOfn[100];    // save currently result

long long aPowbModPrime(long long a, long long b)
{
    int index = log(b) / log(2);
    if (aToThePowOfn[index] != 0)
    {
        return aToThePowOfn[index];
    } 
    if (b % 2)
        aToThePowOfn[index] = aPowbModPrime(a, b - 1) % m * a;
    else
    {
        aToThePowOfn[index] = (aPowbModPrime(a, b / 2) % m) * (aPowbModPrime(a, b / 2) % m);
    }
    return aToThePowOfn[index] % m;
}

int main()
{
    // variable of exercise
    int t;  // t <= 10
    cin >> t;   
    long long n;    // n <= 10^18
    int k;          // k <= 10^5; k < m, n

    // variable created
    unsigned long long numerator;
    unsigned long long denominator;
    long long powerOfDeno;
    unsigned long long rs;
    
    while (t > 0)
    {
        cin >> n >> k;
        cin >> m;

        numerator = 1;
        denominator = 1;
        powerOfDeno = m - 2;
        memset(aToThePowOfn, 0, sizeof(aToThePowOfn));  // refresh array

        // A / B mod m = (A mod m * B^(m - 2) mod m) mod m
        for (int i = 1; i <= k; i++)
        {
            // handle A mod m
            numerator *= (n - k + i) % m;
            numerator %= m;
            if (numerator == 0)
                break;
            
            // handle B mod m
            denominator *= i % m;
            denominator %= m;
        }
        if (numerator == 0)
            rs = 0;
        else
        {
            denominator %= m;
            aToThePowOfn[0] = denominator;

            unsigned long long tmp = aPowbModPrime(denominator, powerOfDeno);
            rs = (numerator * tmp) % m;
        }

        cout << rs << endl;

        t--;
    }
    return 0;
}

// https://tienichnho.com/to-hop-chap
// https://www.wolframalpha.com/
// https://kiendt.me/2017/12/25/10e9-plus-7-modulo/