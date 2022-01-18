#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    int count;
    int tmp;
    while (t > 0)
    {
        cin >> n;
        count = 0;
        int i = 1;
        while (n > 0)
        {
            cin >> tmp;
            if (tmp > i)
            {
                count += tmp - i;
                i = tmp + 1;
            }
            else
                i++;
            n--;
        }
        cout << count << endl;
        t--;
    }
    return 0;
}