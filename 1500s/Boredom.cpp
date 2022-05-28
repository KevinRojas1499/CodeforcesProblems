#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll  a[100005];
ll dp[100005];

ll n,b,M;
ll solve(int k){
	if(k > M){
		return 0;
	}
	if(dp[k] != -1) return dp[k];
	else{
		ll erase = a[k]*k+solve(k+2);
		ll dont  = solve(k+1);
		return dp[k] = max(erase,dont);
	}
}

int main(){
	cin>>n;
	M = -1;
	for(int i = 0; i<n; i++){
		cin>>b;
		M = max(M,b);
		a[b]++;
	}
	memset(dp, -1,sizeof dp);
	cout<<solve(1)<<"\n";
}
