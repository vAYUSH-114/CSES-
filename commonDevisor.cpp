#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(1e6 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v[a]++;
    }

    for (int i = 1e6; i > 0; i--)
    {
        int ans = 0;
        for (int j = i; j <= 1e6; j += i)
        {
            ans += v[j];
        }
        if (ans >= 2)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}