#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long k = 1;
    while (k != (n + 1))
    {
        long long ans = pow(k, 2);
        long long t = ans * (ans - 1) / 2;
        long long discard = 4 * (k - 1) * (k - 2);
        cout << t - discard << endl;
        k++;
    }

    return 0;
}