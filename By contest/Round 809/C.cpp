#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t,n;
const ll mxN= 1e5+5;

ll dp[mxN], seen[mxN], a[mxN];


ll costOfCool(ll i) {
    if(i >= n-1) return 0;
    if(seen[i]) return dp[i];
    seen[i] = 1;
    ll big = max(a[i-1],a[i+1]);
    if(big < a[i]) dp[i] = costOfCool(i+2);
    else {
        dp[i] = big-a[i]+1 + costOfCool(i+2);
        if(i%2 == 1 && n%2 == 0 && i+1 != n-1) dp[i] = min(dp[i],costOfCool(i+1));
    }  
    return dp[i];
}

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        memset(seen,0,sizeof seen);
        for(int i = 0; i<n; i++) cin>>a[i];
        cout<< costOfCool(1)<<"\n";
    }
}