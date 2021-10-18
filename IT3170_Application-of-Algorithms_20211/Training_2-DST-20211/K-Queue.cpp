#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

void solved(vector<int> walruses, int n)
{
    vector<int> indexOfMin;
    int min = walruses[n - 1] + 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (min >= walruses[i])
        {
            indexOfMin.push_back(i);
            min = walruses[i];
        }
    }
    
    int size = indexOfMin.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (walruses[i] > walruses[indexOfMin[j]])
            {
                cout << indexOfMin[j] - i - 1 << " ";
                break;
            }
            if (i == indexOfMin[j])
            {
                cout << -1 << " ";
                size--;
                break;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<int> walruses;

    int tmp;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        walruses.push_back(tmp);
    }

    solved(walruses, t);

    return 0;
}