#include <bits/stdc++.h>
using namespace std;
void permutation(vector<long long> v, vector<vector<long long>> &p, long long i, vector<long long> temp)
{
    if (i == v.size())
    {
        p.push_back(temp);
        return;
    }
    temp.push_back(v[i]);
    permutation(v, p, i + 1, temp);
    temp.pop_back();
    permutation(v, p, i + 1, temp);
}
int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(k);
    // vector<long long> per;
    for (long long i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    vector<vector<long long>> p;
    long long ans = 0;

    permutation(arr, p, 0, {});
    // sort(p.begin(), p.end(), [](vector<long long> a, vector<long long> b)
    //      { return a.size() < b.size(); });

    // for(auto it : p)
    // {
    //     for(auto i : it)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    // long long siz = p[0].size();
    for (long long i = 0; i < p.size(); i++)
    {
        long long prod = 1;
        if (p[i].size() == 0)
            continue;

        // if (p[i].size() != siz)
        //     siz = p[i].size();
        bool isBreak = false;
        for (long long j = 0; j < p[i].size(); j++)
        {
            long long val = p[i][j];
            if (prod > LLONG_MAX / val)
            {
                isBreak = true;
                break;
            }
            prod *= val;
        }
        if (isBreak || prod > n)
            continue;

        if (p[i].size() % 2 == 1)
            ans += n / prod;
        else
            ans -= n / prod;
    }
    cout << ans << endl;
    return 0;
}