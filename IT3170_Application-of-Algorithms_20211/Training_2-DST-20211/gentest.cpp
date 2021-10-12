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

	int n = random(1, 100);
    int t = random(1, 1000);

	// do {
		inp = freopen("LIS.inp", "w", stdout);
		cout << n << endl;
        while (n > 0)
        {
            cout << random(1, 1000) << " ";
            n--;
        }
        cout << endl;

        cout << t << endl;
        int segment;
        while (t > 0)
        {
            cout << rand() % (n - 1 + 1) + 1 << " " << random(1, 300) << endl;
            t--;
        }
	// } while (t--);
	return 0;
}