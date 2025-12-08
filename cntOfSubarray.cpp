#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll i = 0, j = 0;
    ll ans = 0;
    ll maxi = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n && maxi < x)
        {
            maxi += v[j];
            ++j;
        }

        if (maxi == x)
        {
            ++ans;
        }
        maxi -= v[i];
    }
    cout << ans << endl;

    return 0;
}