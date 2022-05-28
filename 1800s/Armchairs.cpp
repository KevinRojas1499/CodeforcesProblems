#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, tot;
vector<ll> a, oc;

ll dp[5005][5005];

ll solve(ll i, ll j){
    if(i == n && j<tot) return 1000000000;
    if(j == tot) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == 1){
        return dp[i][j] = solve(i+1,j);
    }
    else{
        return dp[i][j] = min(abs(oc[j]-i)+solve(i+1,j+1),solve(i+1,j));
    }
}

int main(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    a.resize(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
        if(a[i] == 1){
            oc.push_back(i);
            tot++;
        }
    }
    cout<<solve(0,0)<<"\n";


}