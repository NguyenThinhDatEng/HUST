#include<iostream>
#include <math.h>
using namespace std;

void solve(int* a, int n, int& count, int segment, long long asphalt)
{
    int mid = a[segment];
    if (mid == asphalt)
        return;

    int previous = a[segment - 1];
    int behind = a[segment + 1];

    if (previous == behind)
    {
        if (previous == mid)
            count += 2;
        else
            if (previous == asphalt)
                count -= 2;
        a[segment] = asphalt;
        return;
    }

    if (previous != mid && behind != mid)
    {
        if (previous == asphalt || behind == asphalt)
            count--;
        a[segment] = asphalt;
        return;
    }

    if (previous != asphalt && behind != asphalt)
        count++;
    a[segment] = asphalt;
}

int main()
{
    int n;  // number of road segments
    cin >> n;
    int* a = new int[n + 2]; // the original asphalt covering the road sections
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[n + 1] = pow(10, 9) + 1;

    int count = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i + 1])
            count++;
    // cout << "count = " << count << endl;
    long long t;  // number of notifications
    cin >> t;
    
    int segment;    // the changed road segment
    long long asphalt;    // type of new asphalt
    while (t > 0)
    {
        cin >> segment;
        cin >> asphalt;
        solve(a, n, count, segment, asphalt);
        cout << count << endl;
        t--;
    }
    return 0;
}