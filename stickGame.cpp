#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }

    vector<int> v(n + 1, 0);
    v[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int q : p) {
            if (i - q >= 0 && v[i - q] == 0) {
                v[i] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (v[i] ? 'W' : 'L');
    }
    cout << '\n';

    return 0;
}
