#include <bits/stdc++.h>
using namespace std;
vector<char> dir = {'L', 'R', 'U', 'D'};
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
void solve(vector<vector<char>> &g, vector<vector<bool>> &v, vector<char> &ans, vector<char> temp, int ai, int aj, int n, int m)
{
    vector<vector<char>> p(n, vector<char>(m));

    queue<pair<int, int>> q;
    q.push({ai, aj});
    v[ai][aj] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!v[nx][ny] && g[nx][ny] != '#')
                {
                    v[nx][ny] = true;
                    p[nx][ny] = dir[k];
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<char>> p(n, vector<char>(m));

    vector<vector<bool>> v(n, vector<bool>(m, false));
    int ai, aj;
    int bi, bj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (g[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({ai, aj});
    v[ai][aj] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny] && g[nx][ny] != '#')
            {
                v[nx][ny] = true;
                p[nx][ny] = dir[k];
                q.push({nx, ny});
            }
        }
    }
    if (!v[bi][bj])
    {
        cout << "NO";
        return 0;
    }
    string ans = "";
    while (bi != ai || bj != aj)
    {
        ans.push_back(p[bi][bj]);
        if (p[bi][bj] == 'L')
            bj++;
        else if (p[bi][bj] == 'R')
            bj--;
        else if (p[bi][bj] == 'U')
            bi++;
        else
            bi--;
    }
    if (ans.size() == 0)
    {
        cout << "NO";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;

    return 0;
}