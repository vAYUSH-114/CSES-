#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<long long> v(n);
    v[0] = x;
    long long sum = 0;
    for (long long i = 1; i < n; i++)
    {
        v[i] = (a * v[i - 1] + b) % c;
    }
    long long ans = 0;
    long long i = 0, j = 0;
    while (i < n && j < n)
    {
        sum += v[j];
        j++;
        if (j >= k)
        {
            ans = ans ^ sum;
            sum -= v[i];
            i++;
        }
    }
    cout << ans << endl;

    return 0;
}