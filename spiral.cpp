#include<bits/stdc++.h>
using namespace std;
long long int solve(int x,int y){
    if(x>=y){
        if(x%2==0){
            int tmpy=1;
            long long int ans=1LL*x*x;
            while(y!=tmpy){
                ans--;
                tmpy++;
            }
            return ans;
        }
        else{
            int tmpx=1;
            int tmpy=x;
            long long int ans=1LL*x*x;
            while(x!=tmpx){
                ans--;
                tmpx++;
            }
            while(y!=tmpy){
                ans--;
                tmpy--;
            }
            return ans;
        }
    }
    else{
        if(y&1){
            int tmpx=1;
            long long int ans=1LL*y*y;
            while(x!=tmpx){
                ans--;
                tmpx++;
            }
            return ans;
        }
        else{
            int tmpx=y;
            int tmpy=1;
            long long int ans=1LL*y*y;
            while(y!=tmpy){
                ans--;
                tmpy++;
            }
            while(x!=tmpx){
                ans--;
                tmpx--;
            }
            return ans;
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<endl;
    }


return 0;
}