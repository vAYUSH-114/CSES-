#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    int m=1e9+7;
    vector<vector<char>> v(n,vector<char>(n));
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[0][0]=='*') {
                cout<<0<<endl;
                return 0;
            }
            if(v[i][j]=='*'){
                continue;
            }
            if(i-1>=0){
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=m;
            }
            if(j-1>=0){
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=m;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;

return 0;
}