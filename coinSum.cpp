#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    long long ans = 0;

    for (long long i = 0; i < n; i++)
    {
        if (ans + 1 < v[i])
        {
            cout << ans + 1 << endl;
            return 0;
        }
        else
        {
            ans += v[i];
        }
    }
    cout << ans+1 << endl;
    return 0;
}