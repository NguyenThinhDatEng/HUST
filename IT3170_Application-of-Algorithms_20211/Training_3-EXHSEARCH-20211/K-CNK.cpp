#include<iostream>
#include<set>
#include<vector>

using namespace std;
vector<vector<long long>> cnk;
long long m;  // m <= 10^18
long long halfN;

long long C(int n, int k)
{
    if (k > halfN)
        k = n - k;
    if (k == 0 || k == n) return 1 % m;
	if (k == 1) return n % m;
	if (cnk[n][k] == 0)
	    cnk[n][k] = C(n - 1, k - 1) % m + C(n - 1, k) % m;
	return cnk[n][k] % m;
}

int main()
{
    int T;  // T <= 10
    cin >> T;
    long long n;    // n <= 10^18
    int k;          // k <= 10^5
    while (T > 0)
    {
        cin >> n >> k;
        cin >> m;
        halfN = n / 2;
        cnk.resize(n + 1);
        for (long long i = 0; i <= n; i++)
            cnk[i].resize(k + 1);

        for (long long i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                cnk[i][k] = 0;

        cout << C(n, k) << endl;
        T--;
    }
    return 0;
}