#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>
#include <deque>
using namespace std;

int binarySearch(vector<int>& v, vector<int>& queue, int age, int l, int r)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;
        int indexOfWal = queue[mid];
        if (age > v[indexOfWal] && age <= v[queue[mid - 1]])
        {
            return indexOfWal;
        }

        if (age <= v[indexOfWal])
            return binarySearch(v, queue, age, mid + 1, r);

        return binarySearch(v, queue, age, l, mid - 1);
    }
    return -1;
}

void solve(int n, vector<int> v)
{
    vector<int> queue;  // save index of walruses
    vector<int> rs;
    int firstWal = v.back();

    // push first walruse to queue
    queue.push_back(n - 1);
    rs.push_back(-1);

    // algo
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > firstWal)
            rs.push_back(n - 1 - i - 1);
        else
        {
            int r = queue.size() - 1;
            int mid = binarySearch(v, queue, v[i], 1, r);
            
            if (mid == -1)
            {
                queue.push_back(i);
                rs.push_back(-1);
            }
            else
            {
                rs.push_back(mid - i - 1);
            }
        }
    }

    reverse(rs.begin(), rs.end());
    for (int i = 0; i < n; i++)
    {
        cout << rs[i] << " ";
    }
}

void input(int &n, vector<int> &v)
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n;         // No. of walruses, 2 ≤ n ≤ 10^5
    vector<int> v; // list of walruses, 1 ≤ v[i] ≤ 10^9

    input(n, v);

    solve(n, v);

    return 0;
}