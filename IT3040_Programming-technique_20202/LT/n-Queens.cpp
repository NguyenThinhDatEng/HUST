// candidate /ˈkændɪdət/: ứng cử viên
#include<iostream>

using namespace std;

const int N_MAX = 20;
int n;
int a[N_MAX];

void print_sol() {
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << (i == n? '\n':' ');
	}
}

bool isCandidate(int k, int j)
{
	for (int i = 1; i < k; i++)
		if (j == a[i] || (k + j) == (a[i] + i) || (k - j) == (i - a[i]))
			return false;
	return true;
}

void TRY(int k)
{
	for (int j = 1; j <= n; j++)
	{
		if (isCandidate(k, j))
		{
			a[k] = j;
			if (k == n)
			{
				print_sol();
			}
			else
				TRY(k + 1);
		}
		if (j == n && a[k] == 0) break;
	}
}

int main()
{
	cout << "\nNguyen Van Thinh 20194178\n" << endl;
	memset(a, 0, sizeof(a));
	cin >> n;
	TRY(1);
	cout << endl;
	return 0;
}