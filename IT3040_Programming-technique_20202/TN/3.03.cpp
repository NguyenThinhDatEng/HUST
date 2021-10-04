#include <iostream>
#include <limits.h>

using namespace std;

int n;		// the number of cities
int** c;	// cost list
int* x;		// the road traveled
int cost = 0;
int minCost = INT_MAX;

void initialize2Darray(int** (&a), int n)
{
	a = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
		*(a + i) = new int[n + 1];
}

void input2Darray(int** (&a), int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
}

bool isCandidate(int j, int k)	// true if the city haven't visited
{
	int i = 0;
	do
	{
		if (j == x[i])
			return false;
		i++;
	} while (i < k);
	return true;
}

void TRY(int k)
{
	for (int j = 2; j <= n; j++)	// Next destination is city j
	{
		if (isCandidate(j, k))
		{
			cost += c[x[k - 1]][j];
			x[k] = j;
			if (k == n - 1)
			{
				cost += c[j][1];	// cost travel from city j to return city 1
				if (cost < minCost) minCost = cost;
				cost -= c[j][1];	// prepare to backtrack
			}
			else
				TRY(k + 1);
			cost -= c[x[k - 1]][j];	// backtracking
		}
	}
}

void free2Darray(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] * (a + i);
	delete[] a;
}

int main()
{
	cin >> n;
	initialize2Darray(c, n);
	input2Darray(c, n);
	x = new int[n + 1];
	x[0] = x[n] = 1;	// start from city 1
	TRY(1);

	cout << minCost;

	free2Darray(c, n);
	delete[] x;
	cout << "\n" << endl;
	return 0;
}