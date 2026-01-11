#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n, map<ll, ll> &mp)
{
    if (n == 0 || n == 1)
        return n;
    if (mp.find(n) != mp.end())
        return mp[n];
    if (n & 1)
        mp[n] = 2 * solve(n / 2, mp) + n / 2 + 1;
    else
        mp[n] = solve(n / 2 - 1, mp) + solve(n / 2, mp) + n / 2;
    return mp[n];
}

int main()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;
    mp[0] = 0;
    mp[1] = 1;
    ll ans = solve(n, mp);
    cout << ans << endl;
}