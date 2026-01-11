#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    long long m = 1e9 + 7;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;  

    for (int j = 0; j < n; j++)
    {
        for (int i = v[j]; i <= x; i++)
        {
            dp[i] = (dp[i] + dp[i - v[j]]) % m;
        }
    }
    cout << dp[x] << endl;
    return 0;
}