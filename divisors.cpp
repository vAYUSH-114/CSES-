#include <bits/stdc++.h>
using namespace std;

long long exp(long long a, long long b, long long m)
{
    long long r = 1;
    a %= m;
    while (b)
    {
        if (b & 1) r = (r * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return r;
}

int main()
{
    long long m = 1e9 + 7;
    long long n;
    cin >> n;

    long long a = 1, b = 1, c = 1, d = 1;
    bool e = true;
    vector<pair<long long, long long>> f;

    while (n--)
    {
        long long x, y;
        cin >> x >> y;
        f.push_back({x, y});

        a = (a * (y + 1)) % m;
        d = (d * (y + 1)) % (2 * (m - 1));

        if (y & 1) e = false;

        // for (long long i = 0; i <= y; i++)
        // {
        // }

        long long p = (exp(x, y + 1, m) - 1 + m) % m;
        long long q = exp(x - 1, m - 2, m);
        b = (b * p) % m;
        b = (b * q) % m;

        c = (c * exp(x, y, m)) % m;
    }

    long long g;

    if (!e)
    {
        g = exp(c, (d / 2) % (m - 1), m);
    }
    else
    {
        long long h = 1;
        for (auto &i : f)
            h = (h * exp(i.first, i.second / 2, m)) % m;

        g = exp(h, d % (m - 1), m);
    }

    cout << a << " " << b << " " << g << endl;
    return 0;
}
