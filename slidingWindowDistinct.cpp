#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<long long, long long> m;
    m.reserve(k * 2);
    m.max_load_factor(0.7);

    vector<long long> result;
    long long i = 0, j = 0;

    while (j < n)
    {
        m[v[j]]++;
        if (j - i + 1 == k)
        {
            result.push_back(m.size());
            m[v[i]]--;
            if (m[v[i]] == 0)
                m.erase(v[i]);
            i++;
        }
        j++;
    }

    for (auto x : result)
        cout << x << " ";
    cout << "\n";
    return 0;
}