#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
const int divisor = pow(10, 9) + 7;
unsigned long long aToThePowOfn[100];

unsigned long long aPowbModPrime(unsigned long long a, unsigned long long b)
{
    int index = log(b) / log(2);
    if (aToThePowOfn[index] != 0) return aToThePowOfn[index];
    if (b % 2)
        aToThePowOfn[index] = aPowbModPrime(a, b - 1) % divisor * a;
    else
    {
        aToThePowOfn[index] = (aPowbModPrime(a, b / 2) % divisor) * (aPowbModPrime(a, b / 2) % divisor);
    }
    return aToThePowOfn[index] % divisor;
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    for (int i = 0; i < 100; i++)
        aToThePowOfn[i] = 0;
    a %= divisor;
    b %= divisor - 1;
    aToThePowOfn[0] = a;
    cout << aPowbModPrime(a, b);
    return 0;
}

/*
Dinh ly Fermat nho cho biet: a^p ≡ a(mod p) với a bat ki và p la so nguyen to,
hay noi cach khac a^p-1 ≡ 1 (mod p),
hay a^q(p-1) ≡ 1^q ≡ 1 (mod p),
hay a^(q(p-1) + r) = a^q(p-1) * a^r ≡ 1 * a^r (mod p) = a^r (mod p).
Đặt r = b % (m - 1). Ta có x^b ≡ x^r (mod m) với m là số nguyen to.
Buoc nay giam b tu 10^18 xuong r con co ~10^9
*/