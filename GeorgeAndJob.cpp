#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e15;
ll n,m,k,p, dp[5005][5005];
bool seen[5005][5005];
vector<ll> accum;

ll solve(ll i, ll j){
    if(i+m-1 > n && j == 0) return 0;
    else if(i+m-1> n) return -INF;

    if(seen[i][j]) return dp[i][j];
    seen[i][j] = 1;

    return dp[i][j] = max(solve(i+1,j),accum[m+i-1]-accum[i-1] + solve(m+i,j-1));
}

int main () {
    cin>>n>>m>>k;
    accum.assign(n+1,0);
    memset(dp,0,sizeof dp);
    memset(seen,0,sizeof seen);
    for(int i = 1; i<=n; i++){
        cin>>p;
        accum[i] = accum[i-1]+p;
    }
    cout<<solve(1,k)<<"\n";
}