
#include <iostream>
#include <vector>
using namespace std;

int N;
int K1, K2;
vector<int> schedule;
int* numberOf_bit1;

void display()
{
	for (int i = 0; i < N; i++)
		cout << numberOf_bit1[i] << " ";
	cout << endl;
}

bool isCandidate(int k, int i)
{
	if (k == 0)
	{
		numberOf_bit1[0] = i;
		return true;
	}
	if (i == 0)
	{
		if (schedule.at(k - 1) == 0 || numberOf_bit1[k - 1] < K1) return false;
		else
			numberOf_bit1[k] = 0;
	}
	else
		if (numberOf_bit1[k - 1] >= K2) return false;
		else
			numberOf_bit1[k] = numberOf_bit1[k - 1] + 1;
	
	return true;
}

void solution()
{
	int lastBinary = numberOf_bit1[N - 1];
	if (lastBinary == 1 && lastBinary < K1) return;
	for (int element : schedule)
		cout << element;
	cout << endl;
}

void TRY(int k)
{
	for (int i = 0; i <= 1; i++)
		if (isCandidate(k, i))
		{
			schedule.push_back(i);
			if (k == N - 1)
				solution();
			else
				TRY(k + 1);
			schedule.pop_back();
		}
}

int main()
{
	cout << "\nNguyen Van Thinh 20194178\n" << endl;
	cin >> N >> K1 >> K2;
	numberOf_bit1 = new int[N];
	for (int i = 0; i < N; i++)
		numberOf_bit1[i] = 0;
	TRY(0);
	delete[] numberOf_bit1;
	//cout << "\n" << endl;
	return 0;
}