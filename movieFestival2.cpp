#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](auto &x, auto &y){
        return x.second < y.second;
    });

    multiset<ll> st;
    ll ans = 0;

    for (int i = 0; i < k; i++)
        st.insert(0);

    for (int i = 0; i < n; i++)
    {
        auto it = st.upper_bound(a[i].first);
        if (it == st.begin()) continue;
        --it;
        st.erase(it);
        st.insert(a[i].second);
        ans++;
    }

    cout << ans << endl;
    return 0;
}
