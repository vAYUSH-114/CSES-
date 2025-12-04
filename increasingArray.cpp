#include <bits/stdc++.h>
using namespace std;
long long int solve(int n,vector<int> &arr){
    long long int ans=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            ans+=arr[i]-arr[i+1];
            arr[i+1]=arr[i];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,arr)<<endl;

    return 0;
}