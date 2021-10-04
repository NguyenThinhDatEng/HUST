#include<iostream>

using namespace std;

void showSubSeqOfArray(int* a, int n)
{
	int indexEnd = 0;	// print only a fraction from 0 to indexEnd of Array
	while (indexEnd < n)
	{
		for (int i = 0; i <= indexEnd; i++)
			cout << a[i] << " ";
		indexEnd++;
		cout << endl;
	}
}

int main()
{
	int a[] { 1, 3, 4, 2 };
	int n = 4;	// the number of elements of array
	int i = 0;	// in the range 0 to n - 1
	while (i < n)
	{
		showSubSeqOfArray(a + i, n - i);
		i++;
	}
	return 0;
}