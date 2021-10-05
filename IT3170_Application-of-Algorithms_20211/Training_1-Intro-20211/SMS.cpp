#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string word;
    int length = 0;
    int totalNumberOfTypings;
    getline(cin, word);
    int i = 1;
    while (i <= n)
    {
        totalNumberOfTypings = 0;
        getline(cin, word);
        length = word.length();
        for (char c : word)
        {
            if (c % 3 == 1)
                if (c <= 'p')
                    totalNumberOfTypings++;
                else
                    if (c == 's')
                        totalNumberOfTypings += 4;
                    else
                        totalNumberOfTypings += 3;
            else
                if (c % 3 == 2)
                {
                    if (c == ' ') totalNumberOfTypings++;
                    else
                        if (c <= 'q')
                            totalNumberOfTypings += 2;
                        else
                            if (c == 'z')
                                totalNumberOfTypings += 4;
                            else
                                totalNumberOfTypings++;
                }
                else
                    if (c <= 'r')
                        totalNumberOfTypings += 3;
                    else
                        totalNumberOfTypings += 2;
        }
        cout << "Case #" << i << ": " << totalNumberOfTypings << endl;
        i++;
    }
    return 0;
}