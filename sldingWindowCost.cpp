#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    multiset<long long> chhota, bada;
    long long chotaSum = 0;
    long long badaSum = 0;
    for (long long i = 0; i < n; i++)
    {
        if (chhota.empty() || a[i] <= *prev(chhota.end()))
        {
            chhota.insert(a[i]);
            chotaSum += a[i];
        }
        else
        {
            bada.insert(a[i]);
            badaSum += a[i];
        }

        // agr unbalance hai toh size;;;;
        while ((long long)chhota.size() > (k + 1) / 2)
        {
            bada.insert(*prev(chhota.end()));
            chotaSum -= *prev(chhota.end());
            badaSum += *prev(chhota.end());
            chhota.erase(prev(chhota.end()));
        }
        while ((long long)chhota.size() < (k + 1) / 2 && !bada.empty())
        {
            chhota.insert(*bada.begin());
            chotaSum += *bada.begin();
            badaSum -= *bada.begin();
            bada.erase(bada.begin());
        }

        if (i >= k)
        {
            if (a[i - k] <= *prev(chhota.end()))
            {
                chhota.erase(chhota.find(a[i - k]));
                chotaSum -= a[i - k];
            }
            else
            {
                bada.erase(bada.find(a[i - k]));
                badaSum -= a[i - k];
            }
            // agr unbalance hai toh size;;;;
            while ((long long)chhota.size() > (k + 1) / 2)
            {
                bada.insert(*prev(chhota.end()));
                chotaSum -= *prev(chhota.end());
                badaSum += *prev(chhota.end());
                chhota.erase(prev(chhota.end()));
            }
            while ((long long)chhota.size() < (k + 1) / 2 && !bada.empty())
            {

                chhota.insert(*bada.begin());
                chotaSum+=*bada.begin();
                badaSum-=*bada.begin();
                bada.erase(bada.begin());
            }
        }

        if (i >= k - 1)
        {
            long long med = *prev(chhota.end());
            long long ans1 = abs(chotaSum - med * (long long)chhota.size());
            long long ans2 = abs(badaSum - med * (long long)bada.size());
            cout << ans1 + ans2 << " ";
        }
    }

    return 0;
}
