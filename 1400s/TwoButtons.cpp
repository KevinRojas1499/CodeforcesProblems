#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[10005];
bool seen[10005];
ll solve(ll n,ll m){
	if(n==0){
		return 10000000;
	}
	if(n>=m){
		return n-m;
	}
	if(seen[n])
		return dp[n]?dp[n]:10000000;
	seen[n] = 1;
	return dp[n] = 1+min(solve(n-1,m),solve(2*n,m));
}



int main(){
	ll n,m;
	cin>>n>>m;
	cout<<solve(n,m)<<endl;
}
