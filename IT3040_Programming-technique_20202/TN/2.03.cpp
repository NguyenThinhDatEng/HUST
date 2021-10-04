#include <iostream>

using namespace std;

//# Viết hàm get_value
int get_value(int x, int a = 2, int b = 1, int c = 0)
{
    return a * x * x + b * x + c;
}

int main() {
    int x;
    cin >> x;

    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c

    //# Nhập 3 số nguyên a, b, c từ bàn phím
    cin >> a >> b >> c;

    cout << "a=2, b=1, c=0: "<< get_value(x) << endl;
    cout << "a=" << a << ", b=1, c=0: "<< get_value(x, a) << endl;
    cout << "a=" << a << ", b=" << b << ", c=0: " << get_value(x, a, b) << endl;
    cout << "a=" << a << ", b=" << b << ", c=" << c << ": " << get_value(x, a, b, c);

    return 0;
}