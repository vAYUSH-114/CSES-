#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{

    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    int ans = 0;
    while (i <= j)
    {
        if (v[i] + v[j] <= x)
        {
            i++;
        }
        ans++;
        j--;
    }
    cout << ans << endl;

    return 0;
}