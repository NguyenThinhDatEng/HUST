#include <iostream>
#include <iomanip>

using namespace std;
n
int cube(int x) {
    //# trả về lập phương của x
    return x * x * x;
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x) {
    return x * x * x;
}

int main() {
    int n;
    double f;
    cin >> n >> f;

    cout << "Int: "<< cube(n) << endl;
    cout << "Double: " << setprecision(5) << cube(f);

    return 0;
}