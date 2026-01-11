#include <bits/stdc++.h>
using namespace std;
long long solve(long long x, long long n, long long m = 1e9 + 7)
{
    long long res = 1;
    x %= m;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}
int main()
{
    long long m = 1000000007LL;
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long ji = (solve(b, c, m - 1));

        cout << solve(a, ji) << endl;
    }
    return 0;
}