#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    vector<bool> vis(n, false);
    int cnt = 0;
    int i = 1;
    while (cnt != n - 1)
    {
        if (i >= n)
            i = i % n;
        else
        {
            if (!vis[i])
            {
                cnt++;
                vis[i] = true;
                ans.push_back(i + 1);
                i += 2;
            }
            else{
                i++;
            }
        }
    }
    int j;
    for (j = 0; j < n; j++)
    {
        if (vis[j] == false)
            break;
    }
    ans.push_back(j + 1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}