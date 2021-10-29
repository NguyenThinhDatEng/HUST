#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
using coordinates = pair<int, int>;
using vt = pair<coordinates, int>;

int maxMoved = 0;
int size;
int preX, preY;

void insert(vector<vt> &VTCP, int x, int y)
{
    size = VTCP.size();
    int i = 0;
    while (i < size)
    {
        preX = VTCP[i].first.first;
        preY = VTCP[i].first.second;
        if (x == preX)
            if (y == preY)
            {
                VTCP[i].second++;
                maxMoved = max(maxMoved, VTCP[i].second);
                return;
            }
            else if (y < preY)
                break;

        if (x < preX)
            break;
        i++;
    }

    VTCP.insert(VTCP.begin() + i, 1, {{x, y}, 1});
}

int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    int L, C; // 1≤ L, C ≤1000
    vector<coordinates> first;
    vector<coordinates> second;
    int sizeF, sizeS;
    vector<vt> VTCP;
    int x, y;

    while (T > 0)
    {
        cin >> L >> C;

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

        sizeF = first.size();
        sizeS = second.size();

        maxMoved = 0;
        // VTCP is empty
        x = second[0].first - first[0].first;
        y = second[0].second - first[0].second;
        VTCP.push_back({{x, y}, 1});
        for (int j = 1; j < sizeS; j++)
        {
            x = second[j].first - first[0].first;
            y = second[j].second - first[0].second;
            insert(VTCP, x, y);
        }

        // i = 1 -> sizeF, j = 0 -> sizeS
        for (int i = 1; i < sizeF; i++)
        {
            for (int j = 0; j < sizeS; j++)
            {
                x = second[j].first - first[i].first;
                y = second[j].second - first[i].second;
                insert(VTCP, x, y);
            }
        }

        first.clear();
        second.clear();
        VTCP.clear();
        cout << maxMoved << endl;
        T--;
    }
    return 0;
}