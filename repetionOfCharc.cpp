#include <bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int maxi = 0;
    int temp = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            temp++;
            maxi = max(maxi, temp);
        }
        else
        {
            temp = 0;
        }
    }
    return maxi+1;
}

//unorderedMap method





int main()
{
    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}