#include <iostream>
using namespace std;

int main() {
    for (int iTest = 1; iTest <= 50; iTest++) {
        char tmp[50];
        sprintf(tmp, "%d", iTest);
        string seed(tmp);
        system((string("gentest.exe ") + seed).c_str());
        system(string("reroad_1.exe").c_str());
        system(string("REROAD.exe").c_str());
        if (system(string("fc sol1.out sol2.out").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!//n";
            return 0;
        }
        else
            cout << "Test " << iTest << ": CORRECT!//n";
    }
}