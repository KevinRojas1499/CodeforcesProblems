#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n,k,d;
const ll MOD = 1e9+7;

ll dp[105][2];
bool seen[105][2];

ll solve(ll curr, bool found){
	if(curr == n && found)
		return 1;
	else if(curr == n && !found)
		-1;
	else if(curr>n)
		return -1;
	
	if(seen[curr][found]) return dp[curr][found];
	seen[curr][found] = 1;
	ll res = 0;
	for(int i = 1; i<=k; i++){
		res+=max(0ll,solve(curr+i,(i>=d?1:found)));
		res%=MOD;
	}
	res%=MOD;
	return dp[curr][found] = res;	
}
	

int main(){
	cin>>n>>k>>d;
	memset(dp,sizeof dp, 0);
	memset(seen,sizeof seen, 0);
	
	ll res = solve(0,0);
	res = (res+MOD)%MOD;
	cout<<res<<"\n";
}
