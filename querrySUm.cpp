#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    for (long long i = 1; i < n; i++)
        v[i] += v[i - 1];

    while (x--)
    {
        long long q1, q2, q3;
        cin >> q1 >> q2;

        if (q1 == 1)
        {
            cout << v[q2 - 1] << endl;
        }
        else
        {
            cout << v[q2 - 1] - v[q1 - 2] << endl;
        }
    }

return 0;
}