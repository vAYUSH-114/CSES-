#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cross(ll ax, ll ay, ll bx, ll by, ll px, ll py)
{
    return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}

bool onseg(ll ax, ll ay, ll bx, ll by, ll px, ll py)
{
    if (cross(ax, ay, bx, by, px, py) != 0) return false;
    return min(ax, bx) <= px && px <= max(ax, bx) &&
           min(ay, by) <= py && py <= max(ay, by);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    while (q--)
    {
        ll px, py;
        cin >> px >> py;

        bool bndry = false;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            ll x1 = x[i], y1 = y[i];
            ll x2 = x[(i + 1) % n], y2 = y[(i + 1) % n];

            if (onseg(x1, y1, x2, y2, px, py))
            {
                bndry = true;
                break;
            }

            if (y1 > y2)
            {
                swap(x1, x2);
                swap(y1, y2);
            }

            if (py > y1 && py <= y2 && cross(x1, y1, x2, y2, px, py) > 0)
                cnt++;
        }

        if (bndry) cout << "BOUNDARY" << endl;
        else if (cnt & 1) cout << "INSIDE" << endl;
        else cout << "OUTSIDE" << endl;
    }

    return 0;
}
