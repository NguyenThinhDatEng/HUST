#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> used;

void display(int i, char c)
{
  cout << v[i] << " " << c << endl;
}

void solveLeft(int& i, int& wL, int& wR)
{
  if (wL > wR && (wR + v[i]) < wL)
  {
    wR += v[i];
    used[i] = 1;
    display(i, 'R');
  }
  else
    if (wL + v[i] > wR)
    {
      wL += v[i];
      display(i, 'L');
      used[i] = 1;
    }
    else
      {
        int j = i;
        while (j < n && wL + v[j] <= wR)
          j++;
        if (j == n) cout << -1;
        wL += v[j];
        display(j, 'L');
        used[j] = 1;
        i--;        
      }      
}  

void solveRight(int& i, int& wL, int& wR)
{
  if (wR > wL && (wL + v[i]) < wR)
  {
    wL += v[i];
    used[i] = 1;
    display(i, 'L');
  }
  else
    if (wR + v[i] > wL)
    {
      wR += v[i];
      display(i, 'R');
      used[i] = 1;
    }
    else
      {
        int j = i;
        while (j < n && wR + v[j] <= wL)
          j++;
        if (j == n) cout << -1;
        wR += v[j];
        display(j, 'R');
        used[j] = 1;
        i--;        
      }      
}

int main()
{
  string s;
  cin >> n;
  int tmp;
  for (int i = 0; i < n; i++)
  {
      cin >> tmp;
      v.push_back(tmp);
      used.push_back(0);
  }   
  getline(cin, s);
  getline(cin, s);
  sort(v.begin(), v.end());
  int indexOfS = 0;
  int wL = 0, wR = 0;
  for (int i = 0; i < n; i++)
    if (s[indexOfS] == 'L')
    {
      if (used[i] == 0)
      {
        solveLeft(i, wL, wR);
        indexOfS++;
      }
    }
    else
    {
      solveRight(i, wL, wR);
      indexOfS++;
    }
    
  return 0;
}