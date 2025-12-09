#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long q;
    cin >> q;
    vector<long long> v;
    while (q--)
    {
        long long n;
        cin >> n;
        if (n < 9)
        {
            cout << n << endl;
            continue;
        }
        long long sum = 9;
        pair<long long, long long> cmp = {0, 9};
        long long digit = 1;
        while (n > cmp.second)
        {
            sum *= 10;
            digit++;
            long long temp = sum * digit;
            cmp.first = cmp.second;
            cmp.second += temp;
        }
        // cout << "sum " << sum << " cmp " << cmp.first << " " << cmp.second << endl;
        long long fuck = n - cmp.first;
        long long div = fuck / digit;
        long long rem = fuck % digit;
        long long power = pow(10, digit - 1);
        if (rem == 0)
        {
            long long ans = div + power;
            // cout << "ans " << ans << endl;
            ans--;
            cout << ans % 10 << endl;
        }
        else
        {
            long long ans = div + power;
            string str = to_string(ans);
            cout << str[rem - 1] << endl;
        }
    }
    return 0;
}