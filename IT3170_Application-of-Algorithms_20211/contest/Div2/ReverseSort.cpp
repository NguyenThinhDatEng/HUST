#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    string s;
    int n;
    vector<int> head;
    vector<int> tail;
    while (t > 0)
    {
        cin >> n;
        cin >> s;

        if (s.find("10", 0) > n)
        {
            cout << 0 << endl;
            t--;
            continue;
        }

        deque<int> indexOf1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                indexOf1.push_back(i);
        }

        for (int i = n - 1; i > 0 && !indexOf1.empty(); i--)
        {
            if (s[i] == '0')
            {
                head.push_back(indexOf1.front());
                tail.push_back(i);
                indexOf1.pop_front();
            }
        }
        reverse(tail.begin(), tail.end());

        cout << "1" << endl;
        int k = tail.size() * 2;
        cout << k << " ";
        for (int i = 0; i < head.size(); i++)
        {
            cout << head[i] + 1 << " ";
        }

        for (int i = 0; i < tail.size(); i++)
        {
            cout << tail[i] + 1 << " ";
        }

        cout << endl;
        head.clear();
        tail.clear();
        t--;
    }
    return 0;
}