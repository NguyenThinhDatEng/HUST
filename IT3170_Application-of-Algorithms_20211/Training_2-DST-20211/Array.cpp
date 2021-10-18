#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

void solve(vector<int> negative, vector<int> positive)
{
    cout << '1' << " " << negative[0] << endl;
    
    if (positive.size() == 0)
    {
        cout << negative.size() - 1;
        for (int i = 1; i < negative.size(); i++)
            cout << " " << negative[i];
    }
    else
    {
        cout << negative.size() - 1 + positive.size();
        for (int i = 1; i < negative.size(); i++)
            cout << " " << negative[i];
        for (int i = 0; i < positive.size(); i++)
            cout << " " << positive[i];
    }
    
    cout << endl << 1 << " " << '0';
}

int main()
{
    int n; // 3 <= n <= 100
    cin >> n;
    vector<int> negative; // |val| <= 10^3
    vector<int> positive;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > 0)
            positive.push_back(tmp);
        else if (tmp < 0)
                negative.push_back(tmp);
    }

    solve(negative, positive);
    
    return 0;
}