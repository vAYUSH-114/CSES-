#include <bits/stdc++.h>
using namespace std;
void solve(string str)
{
    long long ans = 1;
    long long maxi = 1;
    for (long long i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            ans++;
            maxi = max(maxi, ans);
        }
        else
        {
            ans = 1;
        }
    }
    cout << maxi << endl;
    ;
}
int main()
{
    string str;
    cin >> str;
    solve(str);

    return 0;
}