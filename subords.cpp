#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> tree[200001];

void solve(int src, int par, vector<int> &ans)
{
    int subords = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {
            solve(child, src, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}

int main()
{

    ll t, n, x;
    t = 1;
    while (t--)
    {
        cin >> n;
        vector<int> ans(n + 1);
        for (int i = 2; i < n + 1; i++)
        {
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }
        solve(1, 0, ans);
        for (int i = 1; i < n + 1; i++)
            cout << ans[i] << ' ';
    }
    return 0;
}