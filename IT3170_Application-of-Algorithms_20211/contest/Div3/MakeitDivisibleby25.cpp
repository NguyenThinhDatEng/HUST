#include<iostream>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

long long fromTail(string n, long long k)
{
    // // the last character is '5'
    if (n.back() == '5')
    {
        n.pop_back();
        long long tmpK = k;     // prepare to case '05' is existed
        bool _05 = false;
        while (!n.empty() && n.back() != '2' && n.back() != '7')
        {
            if (n.back() == '0' && _05 == false) // 205, 8005
            {
                _05 = true;
                tmpK = k;
                string tmpN = n;
                // same case the last character is '0'
                tmpN.pop_back();
                tmpK++;
                while (!tmpN.empty() && tmpN.back() != '0' && tmpN.back() != '5')
                {
                    tmpN.pop_back();
                    tmpK++;
                }
            }
            
            n.pop_back();
            k++;
        }
        if (_05)
            return min(k, tmpK);    // 5705
        return k;
    }
    
    // the last character is '0'
    n.pop_back();
    while (!n.empty() && n.back() != '0' && n.back() != '5')
    {
        n.pop_back();
        k++;
    }
    return k;
}
int main()
{
    int t; //  (1 ≤ t ≤ 10^4)   
    cin >> t;
    long long n; // 25 ≤ n ≤ 10^18
    long long k;
    while(t > 0)
    {
        k = 0;
        cin >> n;
        
        if (n % 25 == 0)
        {
            cout << 0 << endl;
            t--;
            continue;
        }

        string s = to_string(n);
        while (s.back() != '5' && s.back() != '0')
        {
            s.pop_back();
            k++;
        }
        cout << fromTail(s, k) << endl;
        t--;
    }
    return 0;
}