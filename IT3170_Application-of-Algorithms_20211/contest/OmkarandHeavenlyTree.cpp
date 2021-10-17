#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<set>

using namespace std;

int main()
{
    int t;  // 1 <= t <= 10^4
    cin >> t;
    int n;  // 3 <= n <= 10^5
    int m;  // 1 <= m < n
    int a, b, c;    // 1 <= a, b, c <= n
    while (t > 0)
    {
        set<int> bi;
        cin >> n >> m;
        while (m > 0)
        {
            cin >> a >> b >> c;
            bi.insert(b);
            m--;
        }

        set<int>:: iterator itr = bi.begin();
        int size = bi.size();
        int i = 1;
        while(i <= size)
        {
            if (*itr != i)
                break;
            i++;
            itr++;
        }   

        for (int j = 1; j <= n; j++)
        {
            if (j != i)
                cout << i << " " << j << endl;
        }
        t--;
    }
    return 0;
}