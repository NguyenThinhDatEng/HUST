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

void input(ull &a, ull &b);

string solve(string A, string B);

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    ull a, b;
    input(a, b);

    string A = to_string(a);
    string B = to_string(b);
    cout << solve(A, B);

    return 0;
}

void input(ull &a, ull &b)
{
    cin >> a >> b;
}

string solve(string A, string B)
{
    int lengthA = A.length();
    int lengthB = B.length();
    int length = lengthA; // the length of the string is shorter
    string longerNum;     // the string is longer

    if (lengthA > lengthB)
    {
        length = lengthB;
        longerNum = A;
    }
    else
        longerNum = B;

    int k = longerNum.length() - length; // the index that used for substr of longerNum
    int lastNumA, lastNumB;
    int sum;
    char lastChar; // convert type of the last number of the sum to char
    int memory = 0;
    string rs = "";
    int i = lengthA - 1; // the last index of A
    int j = lengthB - 1;
    while (length-- > 0)
    {
        lastNumA = A[i--] - '0';
        lastNumB = B[j--] - '0';
        sum = lastNumA + lastNumB + memory;
        if (sum < 10)
        {
            memory = 0;
            lastChar = (char)sum + '0';
            rs = lastChar + rs;
        }
        else
        {
            memory = 1;
            lastChar = (char)sum % 10 + '0';
            rs = lastChar + rs;
        }
    }

    // continue handling
    // case 1
    if (lengthA == lengthB)
    {
        if (memory)
            return '1' + rs;
        return rs;
    }
    // case 2
    if (memory == 0)
    {
        return longerNum.substr(0, k) + rs;
    }

    while (k > 0 && longerNum[k - 1] == '9')
    {
        rs = '0' + rs;
        k--;
    }
    int lastNum;
    if (k)
    {
        lastNum = longerNum[k - 1] - '0' + 1;
        lastChar = (char)lastNum + '0';
        rs = lastChar + rs;
        return longerNum.substr(0, k - 1) + rs;
    }
    return '1' + rs;
}