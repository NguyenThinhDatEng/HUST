#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string& s, int first, int last) {
    if (first >= last) {
        return true;
    }
    if (s[first] != s[last]) {
        return false;
    }
    bool result = palindrome(s, first + 1, last - 1);
    return result;
}

int main() {
    string str;
    getline(cin, str);
    if (palindrome(str, 0, str.length() - 1)) {
        cout << "Palidrome! \n";
    }
    else {
        cout << "Not Palidrome! \n";
    }
}