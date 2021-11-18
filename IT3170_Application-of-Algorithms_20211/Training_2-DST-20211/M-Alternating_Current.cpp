#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <stack>
#include <stdio.h>
using namespace std;
// FILE* inp, *out;

void solve(string s)
{
    stack<int> st;
    for(auto c : s) {
        if(!st.empty() && c == st.top()) st.pop();
        else st.push(c);
    }

    if(st.empty()) cout << "Yes\n";
    else cout << "No\n";
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // inp = freopen("LIS.inp", "r", stdin);
    // out = freopen("sol1.out", "w", stdout);
    // instance variable
    string s; // n is length of s, 1 ≤ n ≤ 100000
    cin >> s;
    
    solve(s);

    return 0;
}
