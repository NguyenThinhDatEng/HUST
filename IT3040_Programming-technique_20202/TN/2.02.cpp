#include <iostream>

using namespace std;

void rotate(int& x, int& y, int& z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int x, y, z;

    cin >> x >> y >> z;

    cout << "Before: " << x << "," << y << "," << z << "\n";
    rotate(x, y, z);
    cout << "After: " << x << "," << y << "," << z << "\n";

    return 0;
}