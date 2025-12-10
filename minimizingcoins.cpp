#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    vector<long long> dp(x + 1, INT_MAX);
    dp[0] = 0; // is coin ko bnane ke liye zero coins ki zrurt hai
    for (long long i = 1; i <= x; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if (v[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    long long ans = (dp[x] < INT_MAX ? dp[x] : -1);
    cout << ans << endl;

    return 0;
}