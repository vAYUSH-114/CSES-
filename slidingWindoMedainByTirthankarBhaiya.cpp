#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    multiset<long long> chhota, bada;

    for (int i = 0; i < n; i++)
    {
        if (chhota.empty() || a[i] <= *prev(chhota.end()))
            chhota.insert(a[i]);
        else
            bada.insert(a[i]);

        while ((int)chhota.size() > (k + 1) / 2)
        {
            bada.insert(*prev(chhota.end()));
            chhota.erase(prev(chhota.end()));
        }
        while ((int)chhota.size() < (k + 1) / 2 && !bada.empty())
        {
            chhota.insert(*bada.begin());
            bada.erase(bada.begin());
        }

        if (i >= k)
        {
            if (a[i - k] <= *prev(chhota.end()))
                chhota.erase(chhota.find(a[i - k]));
            else
                bada.erase(bada.find(a[i - k]));

            while ((int)chhota.size() > (k + 1) / 2)
            {
                bada.insert(*prev(chhota.end()));
                chhota.erase(prev(chhota.end()));
            }
            while ((int)chhota.size() < (k + 1) / 2 && !bada.empty())
            {
                chhota.insert(*bada.begin());
                bada.erase(bada.begin());
            }
        }

        if (i >= k - 1)
            cout << *prev(chhota.end()) << " ";
    }

    return 0;
}
