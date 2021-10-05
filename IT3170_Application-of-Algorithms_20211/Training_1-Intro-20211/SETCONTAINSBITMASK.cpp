#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
using namespace std;

void inputArr(int* a, int& n)
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    int n, m;
    int a[31];
    int b[31];
    inputArr(a, n);
    inputArr(b, m);
    if (m > n)
        cout << 0;
    else
    {
        sort(a, a + n);
        sort(b, b + m);
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] == b[j]) j++;
            i++;
        }
        if (j < m)
            cout << 0;
        else
            cout << 1;
    }    
    return 0;
}