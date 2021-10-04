#include <iostream>
using namespace std;
template <typename T>
//# viết hàm arr_sum
T arr_sum(T *a, int na, T *b, int nb)
{
    for (int i = 1, j = 0; i < na; i++, j++)
        a[0] += a[i] + b[j];
    return a[0] + b[4] + b[3];
}

int main() {
    int val;
    cin >> val;

    {
        int a[] = { 3, 2, 0, val };
        int b[] = { 5, 6, 1, 2, 7 };
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = { 3.0, 2, 0, val * 1.0 };
        double b[] = { 5, 6.1, 1, 2.3, 7 };
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}