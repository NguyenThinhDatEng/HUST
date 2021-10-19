#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int x[4];   // contain result letters
int existed[10];
string send = "2817";
string more = "0368";
string money = "03185";

void solve()
{
    send = "";
    for (int j = 0; j < 4; j++)
        send += to_string(x[j]);

    more = "";
    for (int j = 4; j < 7; j++)
        more += to_string(x[j]);
    more += send[1];

    money = "";
    money += more[0];
    money += more[1];
    money += send[2];
    money += send[1];
    int a = atoi(send.c_str());
    int b = atoi(more.c_str());
    for (int j = 0; j < 10; j++)
    {
        if (existed[j] == 0)
        {
            money += to_string(j);
            int c = atoi(money.c_str());
            if (a + b == c)
            {
                cout << " " << send << endl;
                cout << " " << more << endl;
                cout << money << endl << endl;
            }
            money.pop_back();
        }
    }
}

void TRY(int k, int t)
{
    for (int i = 0; i < 10 && k < t; i++)
    {
        if (existed[i] == 0)
        {
            x[k] = i;
            existed[i] = 1;
            if (k == t - 1)
            {
               solve();
            }
            else
                TRY(k + 1, t);
            existed[i] = 0;
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
        existed[i] = 0;
    TRY(0, 7);
    return 0;
}

/**
 *  send
 *  +
 *  more
 * -----
 * money
 */

