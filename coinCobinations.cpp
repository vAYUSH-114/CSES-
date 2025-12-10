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
    vector<long long> dp(x + 1, -1);
    dp[0] = 0;

    for (long long i = 1; i <= x; i++)
    {
        long long ans = 0;
        for (long long j = 0; j < n; j++)
        {
            if (v[j] <= i)
            {
                if (dp[i - v[j]] != -1)
                {
                    if (dp[i - v[j]] == 0)
                    {
                        ans += dp[i - v[j]] + 1;
                        ans = ans % m;
                    }
                    else
                    {
                        ans += dp[i - v[j]];
                        ans = ans % m;
                    }
                }
            }
        }
        if (ans != 0)
        {
            dp[i] = ans;
        }
    }
    if (dp[x] == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << dp[x] << endl;
    return 0;
}