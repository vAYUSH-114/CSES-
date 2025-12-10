#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long upperBound(vector<ll> &v, ll target)
{
    long long l = 0, h = v.size();
    while (l < h)
    {
        long long m = l + (h - l) / 2;
        if (v[m] <= target)
            l = m + 1;
        else
            h = m;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // one way of doing

    // long long n, m;
    // cin >> n >> m;
    // vector<ll> t(n), p(m);
    // vector<bool> visit(n, false);

    // for (long long i = 0; i < n; i++) cin >> t[i];
    // for (long long i = 0; i < m; i++) cin >> p[i];

    // sort(t.begin(), t.end());

    // for (long long i = 0; i < m; i++)
    // {
    //     long long l = upperBound(t, p[i]) - 1;
    //     if (l >= 0)
    //     {
    //         cout << t[l] << '\n';
    //         t.erase(t.begin() + l);
    //     }
    //     else
    //     {
    //         cout << -1 << '\n';
    //     }
    //     // while (l >= 0)
    //     // {
    //     //     if (!visit[l])
    //     //     {
    //     //         visit[l] = true;
    //     //         cout << t[l] << '\n';
    //     //         t.erase(t.begin() + l);
    //     //         break;
    //     //     }
    //     //     l--;
    //     // }

    //     // if (l < 0)
    //     // {
    //     //     cout << -1 << '\n';
    //     // }
    // }

    long long n, m;
    cin >> n >> m;
    vector<ll> p(m);
    multiset<ll> t;
    vector<bool> visit(n, false);

    for (long long i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        t.insert(x);
    }
    for (long long i = 0; i < m; i++)
        cin >> p[i];
    for (int i = 0; i < m; i++)
    {
        auto y = t.upper_bound(p[i]);
        if (y == t.begin())
        {
            cout << -1 << endl;
        }
        else{
            --y;
            cout<<*y<<endl;
            t.erase(y);
        }
    }
    

    return 0;
}
