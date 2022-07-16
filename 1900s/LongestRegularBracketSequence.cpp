#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s;
const ll mxN = 1e6+5;
ll dp[mxN], n, seen[mxN];

ll solve(ll k) {
    if(k >= n) return 0;
    if(seen[k]) return dp[k];
    seen[k] = 1;
    if(s[k] == ')') return dp[k] = 0;
    
    if(k+1 < n){
        if(s[k+1] == ')') return dp[k] = 2 + solve(k+2);
        else {
            ll next = solve(k+1);
            if(k+ next +1 < n && s[k+next+1] == ')') {
                return dp[k] = 2 + next + solve(k+next+2);
            }
            else {
                return dp[k] = 0;
            }
        }
    }
    return dp[k] = 0;
}

int main () {
    cin>>s;
    n = s.size();
    memset(dp,0,sizeof dp);
    ll m = -1, count = 0;
    for(int i = 0; i<n; i++) {
        m = max(solve(i),m);
    }
    for(int i = 0; i<n; i++) {
        if(dp[i] == m) count++;
    }
    if(m > 0) cout<<m<<" "<<count<<"\n";
    else cout<<"0 1\n";
}