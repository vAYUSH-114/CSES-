#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    if (!(cin >> n >> x))
        return 0;

    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    while (l < r)
    {
        long long s = a[l].first + a[r].first;
        if (s == x)
        {
            cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
            return 0;
        }
        else if (s < x)
            ++l;
        else
            --r;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
