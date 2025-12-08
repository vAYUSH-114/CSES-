#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int n, vector<long long int> &v)
{

    unordered_map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++)
    {
        m[v[i]]++;
    }
    return m.size();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    long long distinct = 0;
    for (long long i = 0; i < n; ++i)
    {
        if (i == 0 || v[i] != v[i - 1])
            ++distinct;
    }
    cout << distinct << endl;

    // cout << solve(n, v) << endl;

    return 0;
}