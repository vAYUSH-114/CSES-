#include <bits/stdc++.h>
using namespace std;

bool checkkk(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string s;
    cin >> s;
    return s == "YES";
}

void solve(vector<int>& a) {
    if (a.size() <= 1) return;

    int m = a.size() / 2;
    vector<int> l(a.begin(), a.begin() + m);
    vector<int> r(a.begin() + m, a.end());

    solve(l);
    solve(r);

    int i = 0, j = 0, k = 0;
    while (i < l.size() && j < r.size()) {
        if (checkkk(l[i], r[j])) a[k++] = l[i++];
        else a[k++] = r[j++];
    }
    while (i < l.size()) a[k++] = l[i++];
    while (j < r.size()) a[k++] = r[j++];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    solve(arr);

    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) a[arr[i]] = i + 1;

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}