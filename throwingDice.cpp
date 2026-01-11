#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
vector<vector<long long>> multiply(vector<vector<long long>> a,
                                   vector<vector<long long>> b)
{
    vector<vector<long long>> r(6, vector<long long>(6, 0));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                r[i][j] = (r[i][j] + (a[i][k] * b[k][j]) % m) % m;
            }
        }
    }
    // r[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m;
    // r[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m;
    // r[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m;
    // r[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m;
    return r;
}

void solve(long long n)
{
    vector<vector<long long>> ans = {{1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}};
    vector<vector<long long>> base = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}};
    vector<vector<long long>> baseAnswers = {{32}, {16}, {8}, {4}, {2}, {1}};
    n = n - 6;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = multiply(ans, base);
        }
            base = multiply(base, base);
            n = n >> 1;
    }
    ans = multiply(ans, baseAnswers);
    cout << ans[0][0] << endl;
}
int main()
{
    long long n;
    cin >> n;
    if (n <= 6)
    {
        cout << (1LL << (n - 1)) << endl;
        return 0;
    }
    solve(n);
    return 0;
}