#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    string r;
    cin >> s >> r;
    deque<char> dq;
    int i = 0, j = 0;
    int ans=0;
    while (i < s.length() && j < r.length())
    {
        if (s[i] == r[j])
        {
            //  dq.push_back(s[i]);
            i++;
            j++;
            if (j == r.length())
            {
                // dq.pop_front();
                ans++;
                j--;
            }
        }
        else
        {
            //  dq.push_back(s[i]);
            i++;
            j = 0;
        }
    }
    cout << ans << endl;

    return 0;
}