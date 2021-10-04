#include <iostream>
#include <iomanip>

using namespace std;

float get_hypotenuse(float x, float y) {
    return sqrt(x * x + y * y);
}

int main() {
    float x, y;
    cin >> x >> y;

    float z = get_hypotenuse(x, y);
    cout << "z = " << fixed << setprecision(2) << get_hypotenuse(x, y) << "\n";

    return 0;
}