#include<iostream>
#include <deque>
using namespace std;

deque<int> de;
void slove(int& turn, int& max)
{
    if (max >= de.front() && max >= de.front())
}

int main()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        de.push_back(tmp);
    }
    if (n == 1)
    {
        cout << "Alice";
        return 0;
    }
    
    int first = de.front(), last = de.back();
    if (n == 2)
    {
        if (de.front() == de.back())
            cout << "Alice";
        else
            cout << "Bob";
        return 0;
    }

    int turn = 0;
    int max;
    if (first > last)
    {
        max = last;
        de.pop_back();
    }
    else
    {
        max = first;
        de.pop_front();
    }
    turn++;

    int oldMax = max - 1;
    while(!de.empty() && max != oldMax)
    {
        oldMax = max;
        first = de.front();
        last = de.back();
        if (first > max)
        {
            if (last > max)
            {
                if (first >= last)
                {
                    max = last;
                    de.pop_back();
                }
                else
                {
                    max = first;
                    de.pop_front();
                }
                turn++;
            }
            else
                if (last < max)
                {
                    max = first;
                    de.pop_front();
                    turn++;
                }
        }     
        else
            if (last > max)
            {
                max = last;
                de.pop_back();
                turn++;
            }
    }
    if (turn % 2)
        cout << "Alice";
    else
        cout << "Bob";
    return 0;
}