#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

int main()
{
    int t;  // 1 <= t <= 1000
    cin >> t;
    int n;  // 1 <= n <= 2000
    vector<vector<int>> a;  // a[k][] with k is number of transformations
                            // a[][k] array a consisting of n integers
    map<int, int> map_a;    // save number of occurrences of an element of array a
    int q;  // 1 <= q <= 100 000
    int x, k;   // 1 <= x <= n; 0 <= k <= 10^9
    while (t > 0)
    {
        // input
        cin >> n;
        a.resize(1);
        a[0].resize(n + 1);

        int tmp;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            a[0][i] = tmp;
            map_a[tmp]++;
        }

        // algorithm
        // with any array, after t (t < n, n > 1) changes will not be changed anymore
        bool transformation = true;
        int i_th = 1;   // ith sift
        while (transformation)
        {
            a.resize(i_th + 1);
            a[i_th].resize(n + 1);
            // initialize array a[k][] after the ki-th step of transformation
            int tmp;
            for (int i = 1; i <= n; i++)
            {
                tmp = a[i_th - 1][i];
                a[i_th][i] = map_a[tmp];
            }

            // check if the array is still mutable
            for (int i = 1; i <= n; i++)
            {
                if (a[i_th - 1][i] != a[i_th][i])
                {
                    transformation = true;
                    break;
                }
                transformation = false;
                i_th--;     // i_th no increase
            }

            // initialize map after the ki-th step of transformation
            if (transformation)
            {
                map_a.clear();
                for (int i = 1; i <= n; i++)
                {
                    tmp = a[i_th][i];
                    map_a[tmp]++;
                }
            }

            i_th++;
        }

        i_th--; // 1 time excess at i_th++

        cin >> q;
        while (q > 0)
        {
            cin >> x >> k;

            if (n == 1)
            {
                cout << a[0][1] << endl;
                q--;
                continue;
            }

            if (k < i_th)
            {
                cout << a[k][x] << endl;
            }
            else
                cout << a[i_th][x] << endl;

            q--;
        }

        a.clear();
        map_a.clear();

        t--;
    }
    return 0;
}