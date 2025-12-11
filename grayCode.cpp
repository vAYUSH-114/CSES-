#include <bits/stdc++.h>
using namespace std;

string solve(int a, int n)
{
    int g = a ^ (a >> 1);
    string res = "";
    for (int i = n - 1; i >= 0; i--)
    {
        char ch;
        if((g & (1 << i))){
            ch = '1';
        }
        else{
            ch = '0';
        }
        res += ch;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 1 << n; i++)
    {
        cout << solve(i, n) << endl;
    }
}