#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<pair<long long, long long>> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    long long area = 0;
    long long c, y, z, x;
    for (int i = 0; i < n; i++)
    {
        c = v[i].first;
        y = v[i].second;
        z = v[(i + 1) % n].first;
        x = v[(i + 1) % n].second;
        area += c * x - y * z;
    }
    cout << llabs(area) << endl;
}