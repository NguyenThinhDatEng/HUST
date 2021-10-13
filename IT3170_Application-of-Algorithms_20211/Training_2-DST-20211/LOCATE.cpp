#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
using namespace std;
using coordinates = pair<int, int>;
using vt = pair<coordinates, int>;

int maxMoved = 0;

void insert(vector<vt>& VTCP, int x, int y)
{
    int size = VTCP.size();
    if (size == 0)
    {
        VTCP.push_back({{x, y}, 1});
        return;
    }
    
    int i = 0;
    bool exists = false;
    while(i < size)
    {
        if (x == VTCP[i].first.first)
            if (y == VTCP[i].first.second)
            {
                exists = true;
                break;
            }
            else
                if (y < VTCP[i].first.second)
                    break;
        if (x < VTCP[i].first.first)
            break;
        i++;
    }

    if (exists)
    {
        VTCP[i].second++;
        maxMoved = max(maxMoved, VTCP[i].second);
    }
    else
        VTCP.insert(VTCP.begin() + i, 1, {{x, y}, 1});
}

int main()
{
    int T;
    cin >> T;
    int L, C;   // 1≤ L, C ≤1000

    while (T > 0)
    {
        cin >> L >> C;
        vector<coordinates> first;
        vector<coordinates> second;

        int one;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> one;
                if (one)
                    first.push_back({i, j});
            }        

        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> one;
                if (one)
                    second.push_back({i, j});
            }
        
        int sizeF = first.size();
        int sizeS = second.size();
        // for (int i = 0; i < sizeF; i++)
        //     cout << "{" << first[i].first << ", " << first[i].second << "}" << endl;
        
        vector<vt> VTCP;
        maxMoved = 0;
        for (int i = 0; i < sizeF; i++)
        {
            int x;
            int y;
            for (int j = 0; j < sizeS; j++)
            {
                x = second[j].first - first[i].first;
                y = second[j].second - first[i].second;
                insert(VTCP, x, y);
            }
        }

        // for (int i = 0; i < VTCP.size(); i++)
        //     cout << "{" << VTCP[i].first.first << ", " << VTCP[i].first.second << "}" << ", " << VTCP[i].second << endl;

        cout << maxMoved << endl;
        T--;
    }
    return 0;
}