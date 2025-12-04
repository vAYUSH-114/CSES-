#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums,int n)
{
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=ans^nums[i]^(i+1);
    }
    ans=ans^n;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n-1);
    for(int i=0;i<n-1;i++){
        cin>>nums[i];
    }
    cout<<solve(nums,n)<<endl;

    return 0;
}