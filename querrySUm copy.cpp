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
        cin >> q3 >> q1 >> q2;
        if (q3 == 2)
        {
            if (q1 == 1)
            {
                cout << v[q2 - 1] << endl;
            }
            else
            {
                cout << v[q2 - 1] - v[q1 - 2] << endl;
            }
        }
        else
        {
            long long index = q1 - 1;
            long long preIn = index != 0 ? index - 1 : -1;

            long long bhalu;
            if (preIn == -1) bhalu = v[index];
            else bhalu = v[index] - v[preIn];

            long long delta = q2 - bhalu;

            for (long long i = index; i < n; i++)
            {
                v[i] += delta;
            }
        }
    }
    return 0;
}
