#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int lowerBound(vector<ll> &v, ll target)
{
    int l = 0;
    int h = v.size();
    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (v[m] < target)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    return l;
}

int upperBound(vector<ll> &v, ll target)
{
    int l = 0;
    int h = v.size();
    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (v[m] <= target)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> des(n);
    vector<ll> siz(m);
    for (int i = 0; i < n; i++)
        cin >> des[i];
    for (int i = 0; i < m; i++)
        cin >> siz[i];

    sort(des.begin(), des.end());
    sort(siz.begin(), siz.end());

    /////// -----
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {

        while (j < m && siz[j] < (des[i] - k))
        {
            j++;
        }
        if (j < m && siz[j] <= (des[i] + k))
        {
            ans++;
            j++;
        }
    }

    cout << ans << endl;
    /////// -----

    // pair<ll, ll> p;
    // vector<bool> visit(m, false);
    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     p.first = des[i] - k;
    //     p.second = des[i] + k;
    //     int l = lowerBound(siz, p.first);
    //     int h = upperBound(siz, p.second);
    //     while (l < h)
    //     {
    //         if (!visit[l])
    //         {
    //             visit[l] = true;
    //             ans++;
    //             break;
    //         }
    //         l++;
    //     }
    // }

    return 0;
}