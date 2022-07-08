#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 50005, mxK = 505;
ll n,k, dp[mxN][mxK][2];
vector<vector<ll>> adj;

void dfs1(ll cur, ll p ){
    dp[cur][0][0] = 1;
    for(auto neigh : adj[cur]) {
        if(neigh == p) continue;
        dp[cur][1][0]++;
        dfs1(neigh, cur);
        for(int i = 2; i<=k; i++) {
            dp[cur][i][0]+= dp[neigh][i-1][0];
        }
    }
}

void dfs2(ll cur, ll p ){
    dp[cur][0][0] = 1;
    if(p != -1) dp[cur][1][1] = 1;
    if(p != -1)
        for(int i = 2; i<=k; i++) {
            dp[cur][i][1] = dp[p][i-1][1] + dp[p][i-1][0];
            dp[cur][i][1]-= dp[cur][i-2][0];
        }
    for(auto neigh : adj[cur]) {
        if(neigh == p) continue;
        dfs2(neigh, cur);
    }
}

int main () {
    memset(dp,0,sizeof dp);
    cin>>n>>k;
    adj.resize(n+1);
    for(int i = 1; i<n; i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    ll res = 0;
    for(int i = 1; i<=n; i++){
        res+=dp[i][k][0];
        res+=dp[i][k][1];
    }
    cout<<res/2<<"\n";
}