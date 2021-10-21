#include<iostream>
#include<set>
#include<vector>

using namespace std;
unsigned long long** a;
long long m;  // m <= 10^18
long long halfN;

unsigned long long C(int n, int k)
{
    if (k > halfN)
        k = n - k;
    if (k == n || k == 0) return 1;
	if (k == 1) return n;
	if (a[n][k] == 0)
	    a[n][k] = C(n - 1, k - 1) + C(n - 1, k);
	return a[n][k];
}

int main()
{
    int T;  // T <= 10
    cin >> T;
    long long n;    // n <= 10^18
    int k;  // k <= 10^5
    while (T > 0)
    {
        cin >> n >> k;
        cin >> m;
        halfN = n / 2;
        a = new unsigned long long*[n + 1];
        for (long long i = 0; i <= n; i++)
            a[i] = new unsigned long long[k + 1];

        for (long long i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                a[i][j] = 0;
        cout << C(n, k) % m << endl;
        T--;
    }
    return 0;
}