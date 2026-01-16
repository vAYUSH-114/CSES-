#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> vis, active, parent;
vector<int> cycleNodes;

bool dfsCycle(int u)
{
    vis[u] = 1;
    active[u] = 1;

    for (int v : adj[u])
    {
        if (!vis[v])
        {
            parent[v] = u;
            if (dfsCycle(v))
                return true;
        }
        else if (active[v])
        {
            // Found a back edge u -> v
            cycleNodes.push_back(v);
            for (int x = u; x != v; x = parent[x])
            {
                cycleNodes.push_back(x);
            }
            cycleNodes.push_back(v); // close the cycle
            reverse(cycleNodes.begin(), cycleNodes.end());
            return true;
        }
    }

    active[u] = 0;
    return false;
}

void solve(vector<vector<long long>> &g, bool &hasCycle, int &nigaaa)
{
    long long n = g.size() - 1;
    for (long long i = 1; i <= n; i++)
    {
        g[i][i] = 0;
    }

    for (long long via = 1; via <= n; via++)
    {
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                if (g[i][via] != LLONG_MAX && g[via][j] != LLONG_MAX)
                {
                    g[i][j] = min(g[i][j], g[i][via] + g[via][j]);
                }
            }
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        if (g[i][i] < 0)
        {
            hasCycle = true;
            nigaaa = i;
            break;
        }
    }
}
int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, LLONG_MAX));
    // vector<int> adj[n + 1];
    active.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    while (m--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        arr[b][a] = min(c, arr[b][a]);
        adj[a].push_back(b);
    }
    bool hasCycle = false;
    int nigaaa = 0;
    solve(arr, hasCycle, nigaaa);
    if (hasCycle)
    {
        cout << "YES" << endl;
        dfsCycle(nigaaa);
        for (auto node : cycleNodes)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}