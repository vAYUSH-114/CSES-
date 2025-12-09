#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    long long maxi = v[0];
    long long ans = v[0];
    for (long long i = 1; i < n; i++)
    {
        maxi = max(maxi + v[i], v[i]);
        ans = max(ans, maxi);
    }

    cout << ans << endl;
    return 0;
}