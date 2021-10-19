#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<deque>

using namespace std;

void solved(deque<int> walruses, int n)
{
    vector<int> indexOfMin;
    int min = walruses[n - 1] + 1;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (min >= walruses[i])
    //     {
    //         indexOfMin.push_back(i);
    //         min = walruses[i];
    //     }
    // }

    int i;
    while (!walruses.empty())
    {
        i = walruses.size() - 1;
        while (i >= 0)
        {
            if (min >= walruses[i])
            {
                // indexOfMin.push_back(i);
                min = walruses[i];
                if (walruses.front() > min)
                {
                    walruses.pop_front();
                    cout << i - 1 << " ";
                    break;
                }
            }
            i--;
        }
    }

}

int main()
{
    int t;
    cin >> t;
    deque<int> walruses;

    int tmp;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        walruses.push_back(tmp);
    }

    solved(walruses, t);

    return 0;
}