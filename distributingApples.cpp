#include <bits/stdc++.h>
using namespace std;
long long m = 1e9 + 7;
long long f[2000001];

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
    long long n, k;
    cin >> n >> k;
    f[0] = 1;
    for (int i = 1; i <= 2000000; i++)
        f[i] = (f[i - 1] * i) % m;
    long long ans = (f[n + k - 1] * inverse(f[k])) % m;
    ans = (ans * inverse(f[n - 1])) % m;
    cout << ans << endl;

    return 0;
}