#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long res = 0;
    long long m = a[n / 2];
    for (long long i = 0; i < n; i++)
    {
        res += abs(a[i] - m);
    }
    cout << res << endl;

    return 0;
}