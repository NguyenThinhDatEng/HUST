#include <iostream>
#include <stdio.h>
#include <random>
#include <fstream>
#include <time.h>

using namespace std;

FILE* inp;

int random(int L, int H) {
	return (rand() << 16 | rand()) % (H - L + 1) + L;
}

int main(int argc, char** argv) {
	if (argc > 1) 
		srand(atoi(argv[1]));
	else 
		srand(time(NULL));

	int n = random(1, 10);
	int m = random(1, 30);
	int c = 1e6;

	do {
		inp = freopen("LIS.inp", "w", stdout);
		cout << n << " " << m << endl;
		for (int i = 1; i <= n; ++i)
		{
			int second = random(1, n);
			for (int j = 1; j <= second; j++)
			{
				if (j != i)
				{
					cout << i << " " << j << " " << random(1, c) << endl;
					m--;
				}
				if (m == 0) return 0;
			}
		}
	} while (m = random(1, 399));
	return 0;
}