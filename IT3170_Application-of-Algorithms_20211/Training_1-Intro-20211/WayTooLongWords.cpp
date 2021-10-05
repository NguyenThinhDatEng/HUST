#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string word;
    int length = 0;
    getline(cin, word);
    while (n > 0)
    {
        getline(cin, word);
        length = word.length();
        if (length > 10)
            cout << word[0] << length - 2 << word[length - 1] << endl;
        else
            cout << word << endl;
        n--;
    }
    return 0;
}