#include <bits/stdc++.h>
using namespace std;
long long fact(long long n, long long m = 1e9 + 7)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return (1LL * ((n) % m) * ((fact(n - 1)) % m)) % m;
}
int main()
{
    long long MOD = 1e9 + 7;
    string s;
    cin >> s;
    unordered_map<char, long long> m;
    for (long long i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    long long n = s.size();
    long long ans = fact(n) % MOD;
    for (auto it : m)
    {
        ans = ans /fact(it.second);
    }
    // int ans = fact(5);
    cout << ans << endl;
    return 0;
}