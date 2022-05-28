#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 2e5+5;

ll dp[mxN][20];

int main(){
    ll t,n,l,r;
    memset(dp,0,sizeof dp);
    for(int i = 0; i<=mxN; i++){
        for(int k = 0; k<20; k++){
            if(i & 1<<k) dp[i][k] = 1+dp[i-1][k];
            else dp[i][k] = dp[i-1][k];
        }
    }

    cin>>t;
    while(t--){
        cin>>l>>r;
        n = r-l+1;
        ll res = -1;
        for(int i = 0; i<20; i++){
            res = max(res,dp[r][i] - dp[l-1][i]);
        }
        cout<<n-res<<"\n"; 
    }
}