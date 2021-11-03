#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

void input(int& a, int& b) {
    cin >> a >> b;
}

int main()
{
    int a, b;
    input(a, b);
    
    double c = 1.0 * b / a;
    int numberOfYear = log(c) / log(1.5);

    cout << numberOfYear + 1;
    return 0;
}