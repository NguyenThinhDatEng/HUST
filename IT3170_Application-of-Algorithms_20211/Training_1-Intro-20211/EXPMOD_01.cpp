#include<iostream>
#include<math.h>
using namespace std;
int modPrimePow(unsigned long long a, unsigned long long b, int p)
{
    long ret = 1;
    a %= p;
    b %= p - 1;
    while (b > 0) //vòng lặp phân tích b thành cơ số 2
    {
        if (b % 2 > 0)  //ở vị trí có số 1 thì nhân với a^(2^i) tương ứng. Tất cả các phép nhân đều có phép mod p theo sau.
            ret = ret * a % p;
        a = a * a % p;  //tính tiếp a^(2^(i+1)), a^1 -> a^2 -> a^4 -> a^8 -> a^16 v.v...
        b /= 2;
    }
    return (int) ret;
}

int main()
{
    unsigned long long a; //= 123456789987654321;
    unsigned long long b; //= 546152198651652316;
    int  m = pow(10, 9) + 7;
    cin >> a >> b;
    cout << modPrimePow(a, b, m); //257419741
}