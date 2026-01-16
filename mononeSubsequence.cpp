#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (1LL * k * k < n)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        for (int i = 1; i <= n; i += k)
        {
            int r = min(n, i + k - 1);
            for (int j = r; j >= i; j--)
                cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
