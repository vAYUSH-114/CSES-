#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, t;
    cin >> n >> t;
    vector<pair<long long, long long>> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b)
         { return a.first < b.first; });

    for (long long i = 0; i < n; i++)
    {
        long long t2 = t - v[i].first;
        long long l = i + 1;
        long long j = n - 1;
        while (l < j)
        {
            long long sum = v[l].first + v[j].first;
            if (sum == t2)
            {
                cout << v[i].second + 1 << " " << v[l].second + 1 << " " << v[j].second + 1 << endl;
                return 0;
            }
            else if (sum < t2)
            {
                l++;
            }
            else
            {
                j--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}