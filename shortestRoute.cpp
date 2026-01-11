#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
vector<ll> D(vector<vector<ll>> g[],ll n ,ll s){
    vector<ll> dist(n+1,LLONG_MAX);
    dist[s]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [x,y] = pq.top();
        pq.pop();
        if(x > dist[y]) continue;

        for(auto it:g[y]){
            ll u =it[0];
            ll v=it[1];
            if(dist[u] >dist[y]+v){
                dist[u]=dist[y]+v;
                pq.push({dist[u],u});
            }
        }
    }
    return dist;
}
int main() {
    ll c,e;
    cin>>c>>e;
    vector<vector<ll>> g[c+1];
    while(e--){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
       // g[v].push_back({u,w});
    }
    vector<ll> dist=D(g,c,1);
    for(auto it=1;it<=c;it++){
        cout<<dist[it]<<" ";
    }
    cout<<endl;

return 0;
}