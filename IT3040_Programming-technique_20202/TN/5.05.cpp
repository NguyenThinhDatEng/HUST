#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0))
        {
            found = true;
            cout << "Yes";
            return 0;
        }

    }
    cout << "No";
    return 0;
}
