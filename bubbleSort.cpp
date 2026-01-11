#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ans = v;
    sort(ans.begin(), ans.end());

    unordered_map<int, queue<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[ans[i]].push(i);
    }

    int maxShift = 0;
    for (int i = 0; i < n; i++)
    {
        int sortedPos = pos[v[i]].front();
        pos[v[i]].pop();
        maxShift = max(maxShift, i - sortedPos);
    }

    cout << maxShift << endl;
    return 0;
}