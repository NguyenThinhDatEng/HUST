//
#include <iostream>
#include <vector>
using namespace std;

int T;		// the number of testcases
//# 1 <= H <= N <= 16
int N;		// the length of string
int H;		// the number of 0 bits
vector<int> binaryString;	// string
int counter = 0;		// to count the number of 1 bits were existed

inline bool isCandidate(int k, int i)
{
	if (k == 1)
		return true;
	if (counter > H)
		return false;
	return true;
}

inline void solution()
{
	if (counter == H)
	{
		for (int element : binaryString)
			cout << element;
		cout << endl;
	}
}

void TRY(int k)
{
	for (int i = 0; i <= 1; i++)
		if (isCandidate(k, i))
		{
			binaryString.push_back(i);
			if (i == 1) counter++;
			if (k == N)
				solution();
			else
				TRY(k + 1);
			if (i == 1) counter--;
			binaryString.pop_back();
		}
}

int main()
{
	//cout << "\nNguyen Van Thinh 20194178\n" << endl;
	cin >> T;
	do
	{
		cin >> N >> H;
		TRY(1);
		cout << endl;
		T--;
	} while (T > 0);
	//cout << "\n" << endl;
	return 0;
}