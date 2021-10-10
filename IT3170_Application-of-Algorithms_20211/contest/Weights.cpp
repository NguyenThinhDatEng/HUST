#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int n;
vector<int> v;
string s;
vector<int> used;

bool checkRight(int index, int wL, int wR) {
    if (used[index] == 1) return false;
    if (wR + v[index] > wL)
        return true;
    else
        return false;
}

bool checkLeft(int index, int wL, int wR)
{
    if (used[index] == 1) return false;
    if (wL + v[index] > wR)
            return true;
        else
            return false;
}

void solve(int value, char c)
{
    cout << value << " " << c << endl;    
}

void TRY(int k, int wL, int wR)
{
    for (int i = 0; i < n; i++)
    {
        char c = s[k];
        if (c == 'L' && checkLeft(i, wL, wR))
        {
            wL += v[i];
            used[i] = 1;
            TRY(k + 1, wL, wR);
        }
        else
            if (checkRight(i, wL, wR))
            {
                wR += v[i];
                used[i] = 1;
                TRY(k + 1, wL, wR);
            }
    }
}
int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        used[i] = 0;
    }   
    getline(cin, s);
    getline(cin, s);
    TRY(0, 0, 0);
    return 0;
}