#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

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
    int n;
    vector<int> v;
    int count = 0;

    input(n, v);

    int j;
    int countTmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            if (countTmp > 0)
            {
                countTmp--;
            }
            else
            {
                count++;
                countTmp = 0;
            }
        }
        else
        {
            countTmp += v[i];
        }
    }

    cout << count;
    return 0;
}