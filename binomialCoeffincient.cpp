#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
long long f[1000001];
long long fact(long long n, long long m = 1e9 + 7)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return (1LL * ((n) % m) * ((fact(n - 1)) % m)) % m;
}

long long bino(long long a, long long b, long long m = 1e9 + 7)
{
    return 1LL * (((fact(a)) / ((fact(b)) * (fact(a - b)))) % m);
}

long long power(long long a, long long b, long long m)
{
    long long res = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

long long inverse(long long a, long long m = 1e9 + 7)
{
    return power(a, m - 2, m);
}

int main()
{
    f[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        f[i] = (f[i - 1] * i) % m;

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = f[a];
        ans = (ans * inverse(f[b])) % m;
        ans = (ans * inverse(f[a - b])) % m;
        cout << ans << endl;
    }
}