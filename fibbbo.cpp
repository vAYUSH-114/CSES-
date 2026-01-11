#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>> a,
                                   vector<vector<long long>> b)
{
    vector<vector<long long>> r(2, vector<long long>(2));
    r[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % m;
    r[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % m;
    r[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % m;
    r[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % m;
    return r;
}

void solve(long long n)
{
    vector<vector<long long>> ans = {{1, 0}, {0, 1}};
    vector<vector<long long>> base = {{1, 1}, {1, 0}};

    while (n > 0)
    {
        if (n & 1)
            ans = multiply(ans, base);

        base = multiply(base, base);
        n >>= 1;
    }

    cout << ans[0][0] << endl;
}

int main()
{

    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
    }
    else
    {
        solve(n - 1);
    }

    return 0;
}