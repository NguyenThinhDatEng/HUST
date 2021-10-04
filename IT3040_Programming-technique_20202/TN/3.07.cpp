﻿#include <iostream>
#include <stack>
using namespace std;

struct state {
    int i;      // from 1 to n - the length of binary sequence
    int j;      
    int old_L;  // old L (L is the number of consecutive suffix 1)
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0) :     // default parameters
        i(_i), j(_j), old_L(_L) {}                  // sign i = _i;
};                                                  // <name_struct> (parameters) : <practice to sign> {}
                                                            
int main() {
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
    int n, k;       // n characters in a line
    cin >> n >> k;  // there are no k number 1s in a row

    int* x = new int[n + 1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;

    s.push(state(1, 0));
    while (!s.empty()) {
        state& top = s.top();
        //# if a new binary sequence is found
        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }

        //# Khử đệ quy
        if (top.j > 0) L = top.old_L;

        if (top.j > 1) {
            s.pop();
            continue;
        }

        if (L + 1 < k || top.j == 0) {
            x[top.i] = top.j;
            top.old_L = L;
            if (top.j) {
                L = L + 1;
            }
            else { L = 0; }
            s.push(state(top.i + 1, 0));
        }
        top.j++;
    }
    delete[] x;
    return 0;
}