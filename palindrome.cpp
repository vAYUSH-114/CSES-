#include<bits/stdc++.h>
using namespace std;
string generatePall(string str){
    vector<int> freq(26,0);
    for(char ch:str){
        freq[ch-'A']++;
    }
    pair<int,int> cntOdd={0,-1};
    for(int i=0;i<26;i++){
        if(freq[i]%2!=0){
            cntOdd.first++;
            cntOdd.second=i;
        }
    }
    if(cntOdd.first>1){
        return "NO SOLUTION";
    }
    string firstHalf="";
    for(int i=0;i<26;i++){
        int size;
        if(freq[i]!=0 && i!=cntOdd.second){
            size=freq[i]/2;
            firstHalf+=string(size, (char)(i+'A'));
        }
    }
    string secondHalf=firstHalf;
    reverse(secondHalf.begin(),secondHalf.end());
    string middle;
    if(cntOdd.first==1){
        middle=string(freq[cntOdd.second],'A'+cntOdd.second);
    }
    return firstHalf+middle+secondHalf;
}
int main() {
    string str;
    cin>>str;
    cout<<generatePall(str)<<endl;

return 0;
}