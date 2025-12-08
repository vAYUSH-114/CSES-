#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    int cnt = 0;
    int temp = true;
    int i = 1;
    while (temp)
    {
        int divide = n / pow(5, i);
        if (divide == 0)
        {
            temp = false;
        }
        cnt += divide;
        i++;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}