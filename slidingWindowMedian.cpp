#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> v(n);
    multiset<long long> ans;
    for (long long i = 0; i < n; i++)
        cin >> v[i];

    long long i = 0, j = 0;

    while (i < n && j < n)
    {
        ans.insert(v[j]);
        j++;
        if (j - i == k)
        {
            auto it = ans.begin();
            advance(it, (k - 1) / 2);
            cout << *it << " ";
            ans.erase(ans.find(v[i]));
            i++;
        }
    }

    return 0;
}