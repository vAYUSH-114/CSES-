#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(ll n, ll m = 1e9 + 7)
{
    vector<ll> dp(max<ll>(n + 1, 7), 0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;

    if (n <= 6)
    {
        cout << dp[n] << endl;
        return;
    }
    for (ll i = 7; i <= n; i++)
    {
        ll j = i - 1;
        ll sum = 0;
        while (j != i - 6 - 1)
        {
            sum += dp[j];
            if (sum >= m)
            {
                sum = sum % m;
            }
            j--;
        }
        dp[i] = sum;
    }
    cout << dp[n] << endl;
}
int main()
{
    ll n;
    cin >> n;
    solve(n);
    return 0;
}