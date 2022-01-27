#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>

#define ll long long
#define ull unsigned long long

using namespace std;

// instance variable
int n;         // number of rectangles 1 ≤ n ≤ 10^6
vector<int> l; // height of the rectangle 0 ≤ li ≤ 10^8

void input()
{
    cin >> n;
    l.resize(n + 2);
    l[0] = l[n + 1] = -1;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        l[i] = tmp;
    }
}

void solve()
{
    while (1)
    {
        input();
        if (n == 0)
            break;
        // algorithms
        stack<int> leftCandidate, rightCandidate; // save the most appropriate indexes for consider
        vector<int> L, R;                         // L[i], R[i] store the index of the rectangle closest to i

        // generate L, R
        for (int i = 1; i <= n; i++)
        {
            leftCandidate.push(i - 1);
            int index = leftCandidate.top();
            while (l[i] <= l[index])
            {
                leftCandidate.pop();
                index = leftCandidate.top();
            }
            L.push_back(index);

            rightCandidate.push(n + 2 - i);
            index = rightCandidate.top();
            while (l[n + 1 - i] <= l[index])
            {
                rightCandidate.pop();
                index = rightCandidate.top();
            }
            R.push_back(index);
        }

        // summarizing results
        ll maxS = 0;
        ll S;
        for (int i = 0; i < n; i++)
        {
            S = 1LL * (R[n - i - 1] - L[i] - 1) * l[i + 1]; // 10^16
            maxS = max(S, maxS);
        }
        cout << maxS << endl;
        l.clear();
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
