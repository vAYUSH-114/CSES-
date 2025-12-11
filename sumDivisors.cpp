#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M = 1000000007;

ll totalSum(ll n)
{
    if (n <= 0)
        return 0;
    ll a, b;
    if (n & 1)
    {
        a = n;
        b = (n + 1) / 2;
    }
    else
    {
        a = n / 2;
        b = n + 1;
    }
    a %= M;
    b %= M;
    return ((a * b) % M);
}

int main()
{
    ll t;
    if (!(cin >> t))
        return 0;

    ll sum = 0;
    for (ll x = 1; x * x <= t; ++x)
    {
        ll cnt = t / x - x + 1;
        sum = (sum + (cnt % M) * (x % M)) % M;

        ll add = (totalSum(t / x) - totalSum(x)) % M;
        if (add < 0)
            add += M;
        sum += add;
        if (sum >= M)
            sum -= M;
    }

    cout << sum % M << '\n';
    return 0;
}
