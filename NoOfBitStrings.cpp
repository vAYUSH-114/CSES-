#include <bits/stdc++.h>
using namespace std;
long long int mod=1e9+7;
long long int solve(int n){
    long long int ans=1;
    while(n--){
        ans=(ans*2)%mod;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<solve(n)<<endl;

    return 0;
}