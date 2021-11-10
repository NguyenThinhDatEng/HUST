#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<stack>

using namespace std;

void input(int& n, vector<int>& v)
{
    cin >> n;
    int tmp;
    v.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(-1);
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    int n = 1;
    vector<int> v;
    vector<int> L, R;
    int maxS;
    while (n)
    {
        input(n, v);
        if (n == 0)
            break;
        stack<int> left, right;
        maxS = 0;

        int tmp;
        int leftIndex, rightIndex;
        for (int i = 1; i <= n; i++)
        {
            left.push(i - 1);
            leftIndex = left.top();
            while (v[i] < v[leftIndex])
            {
                left.pop();
                leftIndex = left.top();
            }
            L.push_back(leftIndex);

            right.push(n - i + 2);
            rightIndex = right.top();
            while (v[n - i + 1] <= v[rightIndex])
            {
                right.pop();
                rightIndex = right.top();
            }
            R.push_back(rightIndex);
        }
        
        for (int i = 0; i < n; i++)
        {
            maxS = max(maxS, (R[n - i - 1] - L[i] - 1) * v[i + 1]);
        }
        cout << maxS << endl;
        v.clear();
        L.clear();
        R.clear();
    }
    return 0;
}