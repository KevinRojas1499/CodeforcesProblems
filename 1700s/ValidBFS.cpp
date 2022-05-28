#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n,x,y;
    cin>>n;
    vector<set<ll>> adj(n+1);
    for(int i = 0; i<n-1; i++) {
        cin>>x>>y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<ll>  dist(n+1), seen(n+1), order(n+1);
    for(int i = 0; i<n; i++) cin>>order[i];
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    seen[1] = 1;
    ll pos = 1;
    bool possible = order[0] == 1;
    while(q.size()){
        ll cur  = q.front();
        q.pop();
        while(pos < n && adj[cur].find(order[pos]) != adj[cur].end() || seen[order[pos]]){
            q.push(order[pos]);
            seen[order[pos]] = 1;
            adj[cur].erase(order[pos]);
            adj[order[pos]].erase(cur);
            pos++;
        }
        if(adj[cur].size() != 0) {
            possible = false; 
            break;
        }
    }

    if(possible) cout<<"Yes\n";
    else cout<<"No\n";
}