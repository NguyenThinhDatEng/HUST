#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

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
        vector<int> bi;
        cin >> n >> m;
        while (m > 0)
        {
            cin >> a >> b >> c;
            bi.push_back(b);
            m--;
        }

        sort(bi.begin(), bi.end());
        int check = 0;
        int size = bi.size();
        int i = 1;
        while(i <= size)
        {
            if (bi[i - 1] != i)
                break;
            i++;
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