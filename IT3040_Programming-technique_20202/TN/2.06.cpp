#include<iostream>

using namespace std;

void div2(int& n)
{
	n /= 2;
}

void mul3plus1(int& n)
{
	n = n * 3 + 1;
}

void printN(int n)
{
	cout << "n = " << n << endl;
}

void simulate(int n, void (*odd)(int&), void (*even)(int&), void (*output)(int)) {
	(*output)(n);
	if (n == 1) return;
	if (n % 2 == 0) (*even)(n);
	else
		(*odd)(n);
	simulate(n, mul3plus1, div2, printN);
}

int main()
{
	int n;
	cin >> n;
	simulate(n, mul3plus1, div2, printN);
	return 0;
}