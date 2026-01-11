#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> p(n + 1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (auto it : v[x])
        {
            if (!vis[it])
            {
                vis[it] = true;
                p[it] = x;
                q.push(it);
            }
        }
    }

    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> ans;
    int cur = n;
    while (cur != -1)
    {
        ans.push_back(cur);
        cur = p[cur];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
