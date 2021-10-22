#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int* w; // contains weight of members
int n;  // number of members
int totalWeight = 0;    // total weight of all members
int half_n;             // n / 2
int* existed;           // mark the member who choosen
int amountOfDifference = 9950;  // 50 members with 1kg vs 50 members with 200kg

void TRY(int k, int wOfTeam, int numberMembers)
{
    if (amountOfDifference == 0)
        return;
    if (k == half_n)
    {
        int tmp = abs(totalWeight / 2 - wOfTeam);   // new amount of difference
        if (amountOfDifference > tmp)
        {
            amountOfDifference = tmp;
        }
        return;
    }

    for (int i = 0; i < n && numberMembers != half_n; i++)
        if (existed[i] == 0)
        {
            existed[i] = 1;
            TRY(k + 1, wOfTeam + w[i], numberMembers + 1);
            existed[i] = 0;
        }
}

int main()
{
    cin >> n;   // n < 100
    w = new int[n];     // weight <= 200
    existed = new int[n];
    half_n = n / 2;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        totalWeight += w[i];
        existed[i] = 0;
    }

    TRY(0, 0, 0);

    if (amountOfDifference)
        cout << amountOfDifference * 2;
    else
        cout << 1;

    return 0;
}