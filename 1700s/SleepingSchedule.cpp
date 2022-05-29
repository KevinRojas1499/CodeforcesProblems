#include <bits/stdc++.h>
#define ll long long 

using namespace std;

ll n,h,l,r, dp[2005][2005], a[2005], seen[2005][2005];

ll mod(ll u){
    return (u%h+h)%h;
}

ll solve(ll u, ll t){
    if(seen[u][t]) return dp[u][t];
    if(u == n) return 0;
    seen[u][t] = 1;
    ll bef = mod(t+a[u]-1+h), aft = mod(t+a[u]+h);
    ll res = max(solve(u+1,aft),solve(u+1,bef));
    if(l<= mod(t+a[u]-1) && mod(t+a[u]-1)<=r) res = max(res,1+solve(u+1,bef));
    if(l<= mod(t+a[u]) && mod(t+a[u]) <=r) res = max(res,1+solve(u+1,aft));
    return dp[u][t] = res;
}

int main() {
    cin>>n>>h>>l>>r;
    memset(dp,0,sizeof dp);
    memset(seen,0,sizeof seen);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
    }

    cout<<solve(0,0)<<"\n";
}