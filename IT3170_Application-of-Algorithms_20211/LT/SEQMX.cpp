#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

double averageMax = -1 * pow(10, 5);

void input(int &n, int &k, vector<int> &v, vector<long long> &sum)
{
    cin >> n >> k;
    long long tmpSum = 0;
    int tmp;

    for (int i = 0; i < k; i++)
    {
        cin >> tmp;
        tmpSum += tmp;
        v.push_back(tmp);
    }
    averageMax = max(averageMax, 1.0 * tmpSum / k);
    sum.push_back(tmpSum);

    for (int i = k; i < n; i++)
    {
        tmpSum -= v[i - k];
        cin >> tmp;
        tmpSum += tmp;
        sum.push_back(tmpSum);
        averageMax = max(averageMax, 1.0 * tmpSum / k);
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
    vector<long long> sum;
    int k;
    input(n, k, v, sum);

    // algo
    cout << fixed << setprecision(5);
    
    double average;
    int j;
    for (int i = 0; i < n - k; i++)
    {
        j = i + k;
        while (j < n && v[j] > j)
        {
            average = 1.0 * (sum[i] + v[i + k]) / (i + k);
            averageMax = max(averageMax, average);
            j++;
        }
    }

    cout << averageMax;

    return 0;
}