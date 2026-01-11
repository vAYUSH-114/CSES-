#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b;
    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0.0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s <= 6 * n; s++)
        {
            for (int d = 1; d <= 6; d++)
            {
                if (s >= d)
                {
                    dp[i][s] += dp[i - 1][s - d];
                }
            }
        }
    }
    double fav = 0.0;
    for (int s = a; s <= b; s++)
    {
        fav += dp[n][s];
    }
    for (int i = 0; i < n; i++)
    {
        fav = fav / 6;
    }
    cout << fixed << setprecision(6) << fav << endl;
    return 0;
}