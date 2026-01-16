#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    dp[0][0] = true;

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i - 1] && dp[i - 1][j - a[i - 1]])
            {
                dp[i][j] = true;
            }
        }
    }

    vector<long long> din;
    for (long long i = 1; i <= sum; i++)
    {
        if (dp[n][i])
            din.push_back(i);
    }

    cout << din.size() << endl;
    for (auto it : din)
        cout << it << " ";
    cout << endl;

    return 0;
}
