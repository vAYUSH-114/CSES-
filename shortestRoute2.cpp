#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<long long>> &g)
{
    long long n = g.size() - 1;
    for (long long i = 1; i <= n; i++)
    {
        g[i][i] = 0;
    }

    for (long long via = 1; via <= n; via++)
    {
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                if (g[i][via] != LLONG_MAX && g[via][j] != LLONG_MAX)
                    g[i][j] = min(g[i][j], g[i][via] + g[via][j]);
            }
        }
    }
}
int main()
{
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, LLONG_MAX));
    while (m--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(c, arr[a][b]);
        arr[b][a] = min(c, arr[b][a]);
    }
    solve(arr);
    while (q--)
    {
        long long a, b;
        cin >> a >> b;
        if (arr[a][b] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << arr[a][b] << endl;
    }

    return 0;
}