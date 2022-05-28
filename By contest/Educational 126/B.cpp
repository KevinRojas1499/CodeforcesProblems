#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[32780];
const ll MOD = 32768;


int main(){
    ll n,a;
    cin>>n;
    ll inf = 1e16;
    vector<vector<ll>> adj(MOD+1);
    memset(dp,0 ,sizeof dp);
    dp[0] = dp[MOD] = 0;
    for(int i = 0; i<32768; i++){
        ll v = ((2*i)%MOD+MOD)%MOD, w = ((i+1)%MOD+MOD)%MOD;
        adj[v].push_back(i);
        adj[w].push_back(i);
    }
    vector<bool> seen(MOD+1);
    queue<ll> q;
    q.push(0);
    while(q.size()){
        ll cur = q.front();
        q.pop();
        for(auto v : adj[cur]){
            if(seen[v]) continue;
            dp[v] = dp[cur]+1;
            seen[v] = 1;
            q.push(v);
        }
    }
    for(int i = 0; i<n; i++){
        cin>>a;
        cout<<dp[a]-1<<" ";
    }
    
}