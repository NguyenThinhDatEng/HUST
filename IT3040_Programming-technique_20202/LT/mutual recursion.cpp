#include <iostream>

using namespace std;

int X(int n);
int Y(int n);

//#a
auto sumRecursive(int n)
{
	long long sum = 0;
	int i = 0;
	do
	{
		i++;
		sum += X(i) + Y(i);
	} while (i != n);
	return sum;
}

//#b
long long sum(int n)
{
	long long sum = 30;
	if (n < 5)
		switch (n)
		{
		case 1: return 3;
		case 2: return 9;
		case 3: return 18;
		case 4: return 30;
		}
	else
	{
		int x1 = 1, x2 = 2, x3 = 3, x4 = 4;
		int y1 = 2, y2 = 4, y3 = 6, y4 = 8;
		int x, y;
		do
		{
			x = y4 + x3 + y2 + x1;
			y = x4 + y3 + x2 + y1;

			x1 = x2; x2 = x3; x3 = x4;
			x4 = x;

			y1 = y2; y2 = y3; y3 = y4;
			y4 = y;

			sum += x + y;
			n--;
		} while (n > 4);
	}
	return sum;
}

int main()
{
	cout << "\nNguyen Van Thinh 20194178\n" << endl;
	for (int i = 1; i < 10; i++)
		cout << sumRecursive(i) << "   ";
	cout << endl;
	for (int i = 1; i < 10; i++)
		cout << sum(i) << "   ";
	cout << "\n" << endl;
	return 0;
}

int X(int n)
{
	if (n < 5) return n;
	return Y(n - 1) + X(n - 2) + Y(n - 3) + X(n - 4);
}

int Y(int n)
{
	if (n < 5) return n * 2;
	return X(n - 1) + Y(n - 2) + X(n - 3) + Y(n - 4);
}
