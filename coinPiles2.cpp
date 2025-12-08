#include <bits/stdc++.h>
using namespace std;
string solve(long long int x, long long int y)
{
    
    if ((x + y) % 3 != 0)
    {
        return "NO";
    }
    int diff = abs(x-y);
    if(diff > max(x,y)/2){
        return "NO";
    }
    return "YES";
}
int main()
{
    long long int n;
    cin >> n;
    while (n--)
    {
        long long int x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }

    return 0;
}