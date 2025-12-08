#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{

    long long int sum;
    vector<int> a, b(n, 0);
    n & 1 ? sum = 1LL * ((n + 1) / 2) *n : sum = 1LL * (n / 2) * (n + 1);
    if (sum & 1)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
        long long int half = sum / 2;
        // first half ==-1
        // second half ==0
        long long int sum1 = half;
        for (int i = 1; i <= n; i++)
        {
            a.push_back(i);
        }

        while (sum1 > 0)
        {
            if (sum1 > 0 && sum1 <= n)
            {
                b[sum1 - 1] = -1;
                sum1 = 0;
            }
            else
            {
                b[n - 1] = -1;
                sum1 -= n;
                n--;
            }
        }
        vector<int> res1, res2;
        for (int i = 0; i < a.size(); i++)
        {
            if (b[i] == -1)
            {
                res1.push_back(a[i]);
            }
            else
            {
                res2.push_back(a[i]);
            }
        }
        cout << res1.size() << endl;
        for (int i = 0; i < res1.size(); i++)
        {
            cout << res1[i] << " ";
        }
        cout << endl;
        cout << res2.size() << endl;
        for (int i = 0; i < res2.size(); i++)
        {
            cout << res2[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    solve(n);

    return 0;
}