#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        string str = to_string(i);
        for (auto it : str)
        {
            if (it != '0')
                dp[i] = min(dp[i], dp[i - int(it - '0')] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}