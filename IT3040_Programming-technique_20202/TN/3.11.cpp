#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int n;		// the number of shooting locations
int photographers;	// the number of photographers
int** c;			// cost array
vector<int> lst;	// list of selected places
bool* visited;	// mark the point is visited
int x[1000];		// save the road from first point to last point
int costTotal = 0;
int minCost;

void initializeArr(int** (&a), int n);

inline bool isCandidate(int k, int& location, int& cost);

inline void solution();

void TRY(int k)
{
	for (int index = 1; index < lst.size() - 1; index++)	// first point and last point is fixed => consider from 1 to lst.size() - 1
	{
		int nextLocation = lst.at(index);
		int cost = c[x[k - 1]][nextLocation];
		if (isCandidate(k, nextLocation, cost))
		{
			x[k] = nextLocation;
			costTotal += cost;
			visited[nextLocation] = true;
			if (k == lst.size() - 1)
				solution();
			else
				TRY(k + 1);
			//# backtracking
			visited[nextLocation] = false;
			costTotal -= cost;
		}
	}
}

void free2Darray(int** a, int n);

int main()
{
	//cout << "\nNguyen Van Thinh 20194178\n" << endl;
	cin >> n >> photographers;
	initializeArr(c, n);
	visited = new bool[n + 1];
	for (int i = 0; i <= n; i++)
		visited[i] = false;

	//# read array cost
	int i = 1;
	while (i <= n)
	{
		for (; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> c[i][j];
	}
	
	string s;
	getline(cin, s);
	do {
		string number = "";
		getline(cin, s);
		s = s + ' ';
		for (char c : s)
			if (c >= '0' && c <= '9')
				number += c;
			else
			{
				int tmp = stoi(number, 0, 10);
				lst.push_back(tmp);
				number = "";
			}
		//# prepare to backtracking
		minCost = INT_MAX;
		x[0] = lst.front();
		//# solution
		TRY(1);
		//# result
		if (minCost == INT_MAX) minCost = 0;
		cout << minCost << endl;
		lst.clear();
		photographers--;
	} while (photographers > 0);

	free2Darray(c, n);
	delete[] visited;
	return 0;
}

void initializeArr(int** (&a), int n)
{
	a = new int* [n + 1];
	for (int i = 0; i < n + 1; i++)
		*(a + i) = new int[n + 1];
}

inline bool isCandidate(int k, int& nextLocation, int& cost)
{
	if (k == lst.size() - 1)	// special
	{
		nextLocation = lst.back();
		cost = c[x[k - 1]][nextLocation];
	}
	else
		if (visited[nextLocation]) return false;
	if (cost == 0) return false;
	return true;
}

inline void solution()
{
	if (minCost > costTotal)
		minCost = costTotal;
}

void free2Darray(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] * (a + i);
	delete[] a;
}