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

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n; // 1 ≤ n ≤ 10^6
    cin >> n;

    while (n)
    {
        // input
        vector<int> l(n + 2); // 0 ≤ li ≤ 10^8
        l[0] = l[n + 1] = -1;
        int tmp;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            l[i] = tmp;
        }

        // algorithm
        vector<int> left;
        vector<int> right;

        for (int i = 1; i <= n; i++)
        {
            if (l[i] > l[i - 1])
            {
                left.push_back(i - 1);
                // cout << "i = " << i << " i - 1 = " << i - 1 << endl;
            }
            else
            {
                int index;
                int j = left.size() - 1;
                while (j >= 0)
                {
                    index = left[j];
                    if (l[i] > l[index])
                    {
                        left.push_back(index);
                        break;
                    }
                    j--;
                }
            }

            int indexRight = n - i + 1;
            // cout << indexRight << endl;
            if (l[indexRight] > l[indexRight + 1])
            {
                right.push_back(indexRight + 1);
            }
            else
            {
                int index;
                int j = right.size() - 1;
                while (j >= 0)
                {
                    index = right[j];
                    if (l[indexRight] > l[index])
                    {
                        right.push_back(index);
                        break;
                    }
                    j--;
                }
            }
        }

        reverse(right.begin(), right.end());

        ll maxVal = 0;
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            s = 1LL * (right[i - 1] - left[i - 1] - 1) * l[i];
            maxVal = max(maxVal, s);
        }

        cout << maxVal << endl;
        cin >> n;
    }

    return 0;
}
