#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

void display(int index, int n, int numberOfArr)
{
    cout << numberOfArr << endl;
    for (int i = 0; i < n; i++)
    {
        if (i != index)
            cout << i + 1 << " ";
    }
    cout << endl;
}

bool isComposite(int n)
{
    int sqrtN = sqrt(n);
    if (n < 4)
        return false;
    for (int i = 2; i <= sqrtN; i++)
        if (n % i == 0)
            return true;
    return false;
}

int main()
{
    int t;
    cin >> t; // 1 <= t <= 00
    int n;  // 3 <= n <= 200
    int* a;
    vector<int> x;
    while (t > 0)
    {
        cin >> n;
        a = new int[n];
        int sum  = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        
        if (isComposite(sum))
        {
            display(-1, n, n);
        }

        int tmpSum = sum;
        for (int i = 0; i < n && !isComposite(tmpSum); i++)
        {
            tmpSum = sum - a[i];
            if (isComposite(tmpSum))
            {
                display(i, n, n - 1);
                break;
            }
        }
        t--;
    }
    return 0;
}