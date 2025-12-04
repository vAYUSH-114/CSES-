#include <bits/stdc++.h>
using namespace std;
void solve(long long int n)
{
    while (n != 1)
    {
        cout << n << " ";
        if (n & 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    cout << 1 << "\n";
}
int main()
{
    long long int n;
    cin >> n;
    solve(n);

    return 0;
}