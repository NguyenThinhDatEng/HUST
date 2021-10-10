#include<iostream>
using namespace std;
int aL, bL;     // There are two jugs, a-litres jug and b-litres jug
int c;          // how to get exactly c litres.
int minimalStepsByA(int a, int b, int c, int steps)
{
    if (a == c || b == c) return steps;
    if (a == 0) return minimalStepsByA(aL, b, c, ++steps);
    if (b == 0) return minimalStepsByA(0, a, c, ++steps);
    if ((bL - b) / a == 0)
    {
        if (bL - b == 0) return minimalStepsByA(a, 0, c, ++steps);
        else
            return minimalStepsByA(aL - (bL - b), bL, c, ++steps);
    }
    return minimalStepsByA(0, b + a, c, ++steps);
}

bool specialCase(int& aL, int& bL, int c)
{
    if (aL % 2 == 0 && bL % 2 == 0 && c % 2 != 0)
    {
        cout << -1;
        return false;
    }

    if (aL > bL)
        swap(aL, bL);

    if (c > bL)
    {
        cout << -1;
        return false;
    }

    if (bL % aL == 0 && c % aL != 0)
    {
        cout << -1;
        return false;
    }
    return true;
}

int main()
{
    cin >> aL >> bL;
    cin >> c;      
    if (specialCase(aL, bL, c))
    {
        int aToB = minimalStepsByA(0, 0, c, 0);
        if (c % aL == bL % aL)
        {
            int bToA = (bL - c) / aL * 3 - 1;
            cout << min(aToB, bToA);
        }
        else
            cout << aToB;
    }
    return 0;
}