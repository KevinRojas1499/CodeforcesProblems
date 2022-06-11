#include <bits/stdc++.h>
#define ll long long 

using namespace std;

 ll n;


ll sum(vector<vector<ll>> d, vector<ll> seen){
    ll a = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!seen[i] || !seen[j]) continue;
            a+=d[i][j];
        }
    }
    return a;
}

int main() {
    cin>>n;
    vector<vector<ll>> dist(n,vector<ll>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>dist[i][j];
        }
    }
    vector<ll> order(n), res, seen(n);
    for(int i = 0; i<n; i++){
        cin>>order[i];
        order[i]--;
    }
    reverse(order.begin(),order.end());
    for(auto cur : order){
        seen[cur] = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][cur]+dist[cur][j]);
            }
        }
        res.push_back(sum(dist,seen));
    }
    reverse(res.begin(),res.end());
    for(auto r : res) cout<<r<<" ";
    cout<<"\n";
}