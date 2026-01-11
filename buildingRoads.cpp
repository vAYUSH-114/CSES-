#include <bits/stdc++.h>
using namespace std;
#define N 202020
vector<vector<int>> adj(N);
vector<bool> vis(N, false);
vector<int> ans;
 
void dfs(int n)
{
    vis[n] = true;
    // ans.push_back(n);
    for (auto it : adj[n])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i - 1] << " " << ans[i] << endl;
    }
 
    return 0;
}