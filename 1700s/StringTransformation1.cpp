#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> adj;
vector<ll> seen;


void dfs(ll u ){
    if(seen[u]) return;
    seen[u] = 1;
    for(auto v : adj[u]) dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string a,b; 
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        bool possible = true;
        adj.assign(25,vector<ll>());
        seen.assign(25,false);
        for(int i = 0; i<n; i++){
            ll idx1 = a[i]-'a', idx2 = b[i]-'a'; 
            if(idx1 == idx2) continue;
            else if (idx1<idx2){
                adj[idx1].push_back(idx2);
                adj[idx2].push_back(idx1);
            }
            else possible = false;
        }
        if(!possible) cout<<"-1\n";
        else {
            ll res = 20;
            for(int i = 0; i<20; i++){
                if(!seen[i]) {
                    dfs(i);
                    res--;
                }
            }
            cout<<res<<"\n";
        }
    }
}