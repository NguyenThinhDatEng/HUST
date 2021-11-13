#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<stack>

using namespace std;

void input(int& n, vector<int>& v)
{
    cin >> n;   // 1≤n≤1000000
    int tmp;
    // insert -1 to 2 local (front, back of v)
    v.push_back(-1);
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp; //   0≤tmp≤100000000
        v.push_back(tmp);
    }
    v.push_back(-1);
}

int main()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (0);cout.tie (0);
    int n = 1;  // No. of elements
    vector<int> v;  // contains all of elements
    vector<int> L, R;   // contain index nearest lower column
    long long maxS;
    while (n)
    {
        input(n, v);
        if (n == 0)
            break;
        stack<int> left, right; // contain index temporary nearest lower column
        maxS = 0;
        
        // algorithm
        int leftIndex, rightIndex;
        for (int i = 1; i <= n; i++)
        {
            left.push(i - 1);
            leftIndex = left.top(); // get index
            while (v[i] <= v[leftIndex])
            {
                left.pop();
                leftIndex = left.top();
            }
            L.push_back(leftIndex);

            right.push(n + 2 - i);  // v has n + 2 elements (index of last element is n + 1)
            rightIndex = right.top();
            while (v[n + 1 - i] <= v[rightIndex])
            {
                right.pop();
                rightIndex = right.top();
            }
            R.push_back(rightIndex);
        }
        
        for (int i = 0; i < n; i++)
        {
            long long maxTmp = 1LL * (R[n - i - 1] - L[i] - 1) * v[i + 1];
            maxS = max(maxS, maxTmp);
        }

        // display
        cout << maxS << endl;
        v.clear();
        L.clear();
        R.clear();
    }
    return 0;
}