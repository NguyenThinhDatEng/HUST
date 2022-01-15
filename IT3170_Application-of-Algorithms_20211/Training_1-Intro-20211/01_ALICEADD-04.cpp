#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>

#define ll long long
#define ull unsigned long long

using namespace std;

string add_2_big_numbers(string a, string b);

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    string a, b;
    cin >> a >> b;

    cout << add_2_big_numbers(a, b);

    return 0;
}

string add_2_big_numbers(string a, string b)
{
    // Standardize the number
    while (a.length() > b.length())
        b = '0' + b;
    while (b.length() > a.length())
        a = '0' + a;

    int i = a.length(); // index
    int sum;
    int memory = 0;
    string rs = "";
    char c;
    while (i-- > 0)
    {
        sum = a[i] - '0' + b[i] - '0' + memory;
        memory = sum / 10;
        c = sum % 10 + '0';
        rs = c + rs;
    }
    if (memory)
        return '1' + rs;
    return rs;
}