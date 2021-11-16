#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>  
#include <cstring>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n;  // (1 ≤ n ≤ 50) — the number of commands.
    cin >> n;
    string s;   // length of s belongs to [1, 200]
    getline(cin, s);
    string path = "/";  // cd path
    vector<string> nameFolder;  // save name of folders
    while (n > 0)
    {
        getline(cin, s);
        // pwd
        if (s == "pwd")
        {
            cout << path << endl;
            n--;
            nameFolder.clear();
            continue;
        }

        // cd
        s = s.substr(3); // revoke "cd "
        if (s[0] != '/')    // ".." -> "/.."
            s = '/' + s;
        else
            path = "/";
        int length = s.length();

        // get name of folders
        for (int i = 0; i < length; i++)
        {
            if (s[i] == '/')
            {
                nameFolder.push_back("");
            }
            else
                nameFolder.back() += s[i];
        }

        // algo
        for (string folder : nameFolder)
        {
            if (folder == "..")
            {
                if (path.length() != 1)
                {
                    path.pop_back();
                    while (path.back() != '/')
                    {
                        path.pop_back();
                    }
                }
            }
            else
            {
                folder += "/";
                path += folder;
            }
        }

        nameFolder.clear();
        n--;
    }

    return 0;
}