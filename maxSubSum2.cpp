#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> x(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        pre[i + 1] = pre[i] + x[i];
    }
    multiset<ll> st;
    ll ans = LLONG_MIN;
    for (int r = 0; r < n; r++)
    {
        if (r - a + 1 >= 0)
            st.insert(pre[r - a + 1]);

        if (r - b >= 0)
            st.erase(st.find(pre[r - b]));

        if (!st.empty())
            ans = max(ans, pre[r + 1] - *st.begin());
    }
    cout << ans;
    return 0;
}