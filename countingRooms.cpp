#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j, int n, int m, int &ans, vector<vector<bool>> &visit)
{
    stack<pair<int, int>> s;
    s.push({i, j});
    visit[i][j] = true;
    while (!s.empty())
    {
        int x=s.top().first;
        int y=s.top().second;

        if (y - 1 >= 0 && !visit[x][y - 1] && grid[x][y - 1] == '.')
        {
            s.push({x, y - 1});
            visit[x][y - 1] = true;
        }
        else if (y + 1 < m && !visit[x][y + 1] && grid[x][y + 1] == '.')
        {
            s.push({x, y + 1});
            visit[x][y + 1] = true;
        }
        else if (x - 1 >= 0 && !visit[x - 1][y] && grid[x - 1][y] == '.')
        {
            s.push({x - 1, y});
            visit[x - 1][y] = true;
        }
        else if (x + 1 < n && !visit[x + 1][y] && grid[x + 1][y] == '.')
        {
            s.push({x + 1, y});
            visit[x + 1][y] = true;
        }
        else
        {
            s.pop();
        }
    }
    ans++;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && grid[i][j] == '.')
            {
                dfs(grid, i, j, n, m, ans, visit);
            }
        }
    }

    cout << ans << endl;

    return 0;
}