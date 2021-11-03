#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

void input(int &n, vector<int> &v)
{
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // instance variable
    int n;
    vector<int> v;

    input(n, v);

    int Ser = 0;
    int Dima = 0;
    int turn = 1;
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        if (turn % 2)
            if (v[left] > v[right])
            {
                Ser += v[left];
                left++;
            }
            else
            {
                Ser += v[right];
                right--;
            }
        else
            if (v[left] > v[right])
             {
                Dima += v[left];
                left++;
            }
            else
            {
                Dima += v[right];
                right--;
            }
        turn++;
    }
    
    cout << Ser << " " << Dima;
    return 0;
}