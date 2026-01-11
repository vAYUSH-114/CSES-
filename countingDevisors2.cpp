#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
vector<int> primes;

void primmme() {
    vector<bool> haiKya(MAX+1, true);
    haiKya[0] = haiKya[1] = false;
    for (int i = 2; i*i <= MAX; i++) {
        if (haiKya[i]) {
            for (int j = i*i; j <= MAX; j += i)
                haiKya[j] = false;
        }
    }
    for (int i = 2; i <= MAX; i++)
        if (haiKya[i]) primes.push_back(i);
}


long long solve(long long n) {
    long long res = 1;
    for (auto p : primes) {
        if (1LL * p * p > n) break;
        long long cnt = 0;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        if (cnt > 0) res *= (cnt + 1);
    }
    if (n > 1) res *= 2;
    return res;
}

int main()
{
    primmme();
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}