#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 3e5+5;
vector<vector<ll>> adj;
ll subTreeSize[mxN], dp[mxN];
bool seen[mxN], infected[mxN];
vector<pair<ll,ll>> best;

ll dfs(ll a, ll p) {
    if(adj[a].size() == 0) return subTreeSize[a] = 0;
    else{
        subTreeSize[a] = 0;
        for(auto v : adj[a]){
            if(v == p) continue;
            subTreeSize[a]++;
            subTreeSize[a]+=dfs(v,a);
        }
        return subTreeSize[a];
    }
}

ll solve(ll a, ll p){
    if(seen[a]) return dp[a];
    seen[a] = 1;
    if(adj[a].size() == 1) return dp[a] = 0;
    if(adj[a].size() == 2){
        ll b = adj[a][0];
        if(adj[a][0] == p) b = adj[a][1];
        return dp[a] = subTreeSize[b];
    }
    else{
        ll u = adj[a][0], v = adj[a][1];
        if(u == p) u = adj[a][2];
        if(v == p) v = adj[a][2];
        return dp[a] = max(subTreeSize[u]+solve(v,a),subTreeSize[v]+solve(u,a));
    }
}


int main(){
    ll t,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        adj.assign(n+1,{});
        memset(seen,0,sizeof seen);
        memset(infected,0,sizeof infected);
        for(int i = 0; i<n-1; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        adj[1].push_back(-1);
        dfs(1,-1);
        cout<<solve(1,-1)<<"\n";

    }
}