#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> t;

void build(int v, int l, int r, vector<long long> &a)
{
    if (l == r)
    {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(v * 2, l, mid, a);
    build(v * 2 + 1, mid + 1, r, a);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int query(int v, int l, int r, long long x)
{
    if (t[v] < x)
        return -1;

    if (l == r)
        return l;

    int mid = (l + r) / 2;
    if (t[v * 2] >= x)
        return query(v * 2, l, mid, x);
    else
        return query(v * 2 + 1, mid + 1, r, x);
}

void update(int v, int l, int r, int pos, long long val)
{
    if (l == r)
    {
        t[v] -= val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(v * 2, l, mid, pos, val);
    else
        update(v * 2 + 1, mid + 1, r, pos, val);

    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int main()
{
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    t.assign(4 * n, 0);
    build(1, 1, n, a);

    while (m--)
    {
        long long x;
        cin >> x;

        int idx = query(1, 1, n, x);
        if (idx == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << idx << " ";
            update(1, 1, n, idx, x);
        }
    }

    return 0;
}
