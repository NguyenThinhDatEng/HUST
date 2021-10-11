#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
using element = pair<int, int>;

int solve(int n, int b) {
    int* a = new int[n];
    int signalCutOff = -1;
    int endArr = n - 1;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxHead = a[0];
    vector<element> head;
    for (int i = 1; i < endArr; i++)
    {
        if (maxHead - a[i] >= b)
            head.push_back({i, maxHead});
        maxHead = max(maxHead, a[i]);
    }

    vector<element> tail;
    int maxTail = a[endArr];
    int limit = head[0].first;
    for (int i = endArr - 1; i >= limit; i--)
    {
        if (maxTail - a[i] >= b)
            tail.push_back({i, maxTail});
        maxTail = max(maxTail, a[i]);
    }

    reverse(tail.begin(), tail.end());
    int headSize = head.size();
    int tailSize = tail.size();
    int hFirst, tFirst;
    int i = 0, j = 0;
    while(i < headSize && j < tailSize)
    {
        hFirst = head[i].first;
        tFirst = tail[j].first; 
        if (hFirst <= tFirst)
        {
            if (hFirst == tFirst)
            {
                int tmp = head[i].second + tail[j].second - 2 * a[hFirst];    
                signalCutOff = max(signalCutOff, tmp);
                j++;
            }
        }
        else
            j++;
        i++;
    }
    return signalCutOff;
}

int main()
{
    int n;
    cin >> n;
    int b;
    cin >> b;
    cout << solve(n, b);
    return 0;
}