#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> visi(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        visi[v[i]] = i;
    }

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (visi[i] > visi[i + 1])
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}