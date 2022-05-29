#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll MOD = 1e9+7;
vector<vector<ll>> adj, rev_adj;
vector<ll> order, component,seen;

void dfs1(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    for(auto v: adj[u]) dfs1(v);
    order.push_back(u);
}

void dfs2(ll u){
    if(seen[u]) return;
    seen[u] = 1;
    component.push_back(u);
    for(auto v : rev_adj[u]) dfs2(v); 
}

int main () {
    ll n,m,u,v;
    cin>>n;
    adj.resize(n); rev_adj.resize(n); seen.resize(n,false);
    vector<ll> cost(n);
    for(int i = 0; i<n; i++) cin>>cost[i];
    cin>>m;
    for(int i = 0; i<m; i++){
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for(int i = 0; i<n; i++){
        if(!seen[i]) dfs1(i);
    }
    reverse(order.begin(),order.end());
    seen.assign(n,false);
    ll res = 0, numberOfWays = 1;
    for(int i = 0; i<n; i++){
        u = order[i];
        if(!seen[u]){
            dfs2(u);
        }
        else {
            continue;
        }
        ll minimo = cost[u];
        for(auto a : component){
            minimo = min(minimo, cost[a]);
        }
        ll numMin = 0;
        for(auto a : component){
            if(cost[a] == minimo) numMin++;
        }
        res+=minimo;
        numberOfWays*=numMin;
        numberOfWays%=MOD;
        component.clear();
    }
    numberOfWays+=MOD;
    numberOfWays%=MOD;
    cout<<res<<" "<<numberOfWays<<"\n";

    
}