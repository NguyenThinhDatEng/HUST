#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

void input(vector<int> &v, int &n);

void merge(vector<int> &v, int l, int mid, int r)
{
    if (v[mid] <= v[mid + 1]) // 1 2 3 4 5 6
        return;
    vector<int> tmp; // get elements from smallest to largest
    int i = l;       // the top of left array
    int j = mid + 1; // the top of right array
    while (i <= mid || j <= r)
    {
        if (i <= mid && j <= r)
        {
            if (i <= mid && v[i] <= v[j])
            {
                tmp.push_back(v[i]);
                i++;
            }
            if (j <= r && v[i] >= v[j])
            {
                tmp.push_back(v[j]);
                j++;
            }
        }
        else
        {
            if (j > r)
            {
                for (; i <= mid; i++)
                {
                    tmp.push_back(v[i]);
                }
            }
            else
                for (; j <= r; j++)
                {
                    tmp.push_back(v[j]);
                }
        }
    }

    for (i = l; i <= r; i++)
    {
        v[i] = tmp[i - l];
    }
}

void mergeSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    vector<int> v;
    int n;

    input(v, n);
    mergeSort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

void input(vector<int> &v, int &n)
{
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}