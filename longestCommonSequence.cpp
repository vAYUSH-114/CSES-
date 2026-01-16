#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> u(m);
    for (int i = 0; i < m; i++)
    {
        cin >> u[i];
    }
    vector<vector<pair<char, int>>> dp(n + 1, vector<pair<char, int>>(m + 1, make_pair('\0', 0)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i - 1] == u[j - 1])
            {
                dp[i][j].second = dp[i - 1][j - 1].second + 1;
                dp[i][j].first = 'D';
            }
            else
            {
                dp[i][j].second = max(dp[i - 1][j].second, dp[i][j - 1].second);
                if (dp[i - 1][j].second > dp[i][j - 1].second)
                {
                    dp[i][j].first = 'U';
                }
                else
                {
                    dp[i][j].first = 'L';
                }
            }
        }
    }
    vector<int> ans(dp[n][m].second);
    int i = n, j = m;
    int t = dp[n][m].second - 1;
    while (i > 0 && j > 0)
    {
        if (dp[i][j].first == 'D')
        {
            ans[t] = v[i - 1];
            i--;
            j--;
            t--;
        }
        else if (dp[i][j].first == 'U')
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << dp[n][m].second << endl;
    for (int i = 0; i < dp[n][m].second; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}