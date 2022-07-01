#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 205;
ll dp[mxN][mxN][mxN];
bool seen[mxN][mxN][mxN];
ll nr,ng,nb;
vector<ll> r, g, b;

ll solve(ll x , ll y, ll z ){
    if( (x == 0 && y == 0) || (x == 0 && z == 0) || (y == 0 && z == 0) ) return 0;
    if(seen[x][y][z]) return dp[x][y][z];
    seen[x][y][z] = 1;
    if(y>0 && z > 0) dp[x][y][z] = max(dp[x][y][z],g[y]*b[z]+solve(x,y-1,z-1));
    if(x>0 && z > 0) dp[x][y][z] = max(dp[x][y][z],r[x]*b[z]+solve(x-1,y,z-1));
    if(x>0 && y > 0) dp[x][y][z] = max(dp[x][y][z],r[x]*g[y]+solve(x-1,y-1,z));
    return dp[x][y][z];
}

int main() {
    cin>>nr>>ng>>nb;
    r.assign(nr+1,0);g.assign(ng+1,0);b.assign(nb+1,0);
    for(int i = 0; i<nr; i++) cin>>r[i+1];
    for(int i = 0; i<ng; i++) cin>>g[i+1];
    for(int i = 0; i<nb; i++) cin>>b[i+1];
    sort(r.begin(),r.end());
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());
    
    memset(dp,0,sizeof dp);
    memset(seen,0,sizeof seen);

    cout<<solve(nr,ng,nb)<<"\n";
}