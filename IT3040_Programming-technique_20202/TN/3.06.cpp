#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b) {
    if (a == b) return a;
    int surplus = 0;
    while (b != 0)
    {
        surplus = a % b;
        a = b;
        b = surplus;
    }
    return a;
}

int main() {
   // cout << "\nNguyen Van Thinh 20194178\n" << endl;
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}