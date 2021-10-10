#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    unsigned long long n;
    while (t > 0)
    {
        cin >> n;
        if (n % 2) {
            cout << n / 2 << " " << n / 2 + 1 << endl;
            t--;
            continue;
        }

        int sqrtN = sqrt(n);

        for (int i = 2; i <= sqrtN; i++)
            if (n % i == 0)
            {
                int divisor = n / i;
                if (divisor % 2 == n % 2)
                    if (i % 2 == 0)
                        cout << divisor - i / 2 << " " << divisor + i / 2 + 1 << endl;
                    else
                        cout << divisor - i / 2 << " " << divisor + i / 2 << endl;
            }
        t--;   
    }
    return 0;
}
/*
    So phan tu le => l r la 2 so le => midNum chan
                    => l r la 2 so chan => n le => loai => chi xet n chan
    so phan tu chan => l r chan le 
*/