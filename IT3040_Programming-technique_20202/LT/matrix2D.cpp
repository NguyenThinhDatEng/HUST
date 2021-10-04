#include<iostream>
#include<iomanip>

using namespace std;

void allocate_mem(int*** arr, int rows, int columns)
{
	int** a = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(a + i) = new int[columns];
	}
	*arr = a;
}

void input(int** arr, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			cin >> arr[i][j];
}

void display2Darray(int** arr, int rows, int columns)
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << setw(6) << right << arr[i][j];
		cout << endl;
	}
	cout << endl;
}

void sumOfTwoSquareArr(int** a, int** b, int** c, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = a[i][j] + b[i][j];
}

void multiply2Matrices(int** a, int** b, int** c, int n)
{
	for (int i = 0; i < n; i++)		// assign all elements of array equal to 0
		for (int j = 0; j < n; j++)
			c[i][j] = 0;

	for (int i = 0; i < n; i++)		// pratice calculation
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
}

void free_mem(int** mt, int m, int n) {
	//# Free memory

	for (int i = 0; i < m; i++)
	{
		delete[] * (mt + i);
	}
	delete[] mt;
}

void main()
{
	int** a, ** b;	// two square matrixs input
	int n;			// the number of rows
	cout << "Enter n = ";
	cin >> n;

	// Allocate for a and b
	allocate_mem(&a, n, n);
	allocate_mem(&b, n, n);

	// enter data for a and b
	cout << "First Array: \n";
	input(a, n, n);
	cout << "Second Array: \n";
	input(b, n, n);

	// show two square matrixs input
	cout << "First Array: \n";
	display2Darray(a, n, n);
	cout << "Second Array: \n";
	display2Darray(b, n, n);

	int** c;		// contain result
	// Allocate for c
	allocate_mem(&c, n, n);

	multiply2Matrices(a, b, c, n);
	cout << "Product of 2 matrices:\n";
	display2Darray(c, n, n);

	sumOfTwoSquareArr(a, b, c, n);
	cout << "The sum of 2 matrices:\n";
	display2Darray(c, n, n);

	free_mem(a, n, n);
	free_mem(b, n, n);
	free_mem(c, n, n);
}