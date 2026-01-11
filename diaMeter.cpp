#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> adj[], int node, int p, int &a, int temp, int &maxNodde)
{
    if (temp > a)
    {
        maxNodde = node;
        a = temp;
    }

    for (auto it : adj[node])
    {
        if (it != p)
            solve(adj, it, node, a, temp + 1, maxNodde);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    int mx = 0, node = 1;
    solve(adj, 1, -1, res, 0, mx);
    res=0;
    solve(adj, mx, -1, res, 0, node);
    cout << res << endl;
    return 0;
}