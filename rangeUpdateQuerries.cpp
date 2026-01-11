#include <bits/stdc++.h>
using namespace std;
vector<long long> v(2000000);
vector<long long> seg(2000000,0);

void solve(long long i, long long low, long long high, long long l, long long r, long long u)
{
    if (high < l || low > r)
    {
        return;
    }
    if (low >= l && high <= r)
    {
        seg[i] += u;
        return;
    }

    long long mid = low + (high - low) / 2;
    solve(2 * i + 1, low, mid, l, r, u);
    solve(2 * i + 2, mid + 1, high, l, r, u);
}

long long querry(long long i, long long low, long long high, long long l)
{
    if (high == low && low == l)
    {
        return seg[i];
    }

    long long mid = low + (high - low) / 2;
    if (l <= mid)
    {
        return seg[i] + querry(2 * i + 1, low, mid, l);
    }
    else
    {
        return seg[i] + querry(2 * i + 2, mid + 1, high, l);
    }
}
int main()
{
    long long t, n;
    cin >> t >> n;
    for (long long i = 0; i < t; i++)
        cin >> v[i];

    while (n--)
    {
        long long x;
        cin >> x;
        if (x == 1)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            solve(0, 0, t - 1, a - 1, b - 1, c);
        }
        else
        {
            long long a;
            cin >> a;
            cout << v[a - 1] + querry(0, 0, t - 1, a - 1) << endl;
        }
    }
    return 0;
}