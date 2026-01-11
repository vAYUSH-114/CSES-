#include <bits/stdc++.h>
using namespace std;
vector<int> v(2000000);
vector<int> seg(2000000);
 
void build(int i, int low, int high)
{
    if (low == high)
    {
        seg[i] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * i + 1, low, mid);
    build(2 * i + 2, mid + 1, high);
 
    seg[i] = (seg[2 * i + 1] ^ seg[2 * i + 2]);
}
 
int querry(int i, int low, int high, int l, int r)
{
    if (high < l || low > r)
        return 0;
    if (low >= l && high <= r)
        return seg[i];
    int mid = low + (high - low) / 2;
    int left = querry(2 * i + 1, low, mid, l, r);
    int right = querry(2 * i + 2, mid + 1, high, l, r);
    return (left ^ right);
}
int main()
{
    int t, n;
    cin >> t >> n;
    for (int i = 0; i < t; i++)
        cin >> v[i];
 
    build(0, 0, t - 1);
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << querry(0, 0, t - 1, a - 1, b - 1) << endl;
    }
 
    return 0;
}
