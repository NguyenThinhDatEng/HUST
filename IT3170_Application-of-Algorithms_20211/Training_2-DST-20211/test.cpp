#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

int x[2]; // contain result letters
int existed[9];
string send = "1";
string more = "2";
string money = "3";
int check = 0;

void TRY(int k, int t);
void solve(int t);

int main()
{
  for (int i = 0; i < 9; i++)
    existed[i] = 0;
  TRY(0, 2);
  cout << " " << send << endl;
  cout << " " << more << endl;
  cout << money;
  return 0;
}

/**
 *  send
 *  +
 *  more
 * -----
 * money
 */

void TRY(int k, int t)
{
  for (int i = 1; i < 6; i++)
  {
    if (existed[i] == 0 && k < t)
    {
      x[k] = i;
      existed[i] = 1;
      if (k == t - 1)
      {
        
      }
      else
        TRY(k + 1, t);
      existed[i] = 0;
    }
  }
}