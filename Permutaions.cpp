#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{

    if (n == 1)
    {
        cout << 1;
        return;
    }
    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3";
        return;
    }
    else
    {

        for (int i = n; i > 0; i -= 2)
        {
            cout << i << " ";
        }
        for (int i = n - 1; i > 0; i -= 2)
        {
            cout << i << " ";
        }
    }

}
int main()
{

    int n;
    cin>>n;
    solve(n);

    return 0;
}