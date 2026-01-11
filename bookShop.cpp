#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x;
    cin >> t >> x;
    vector<int> h(t + 1, 0);
    vector<int> s(t + 1, 0);

    for (int i = 1; i < t + 1; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i < t + 1; i++)
    {
        cin >> s[i];
    }

    vector<vector<int>> dp(t + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - h[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[t][x] << endl;

    return 0;
}