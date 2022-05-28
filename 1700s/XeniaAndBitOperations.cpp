#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 18, mxSize = 1<<18;

ll dp[mxSize][mxN], a[mxSize];
bool seen[mxSize][mxN];


bool affected(ll beg, ll l, ll posChanged){
	return beg<= posChanged && posChanged < beg+l;
}

ll solve(ll beg, ll length, ll posChanged, bool xorr){
	if(seen[beg][length] && !affected(beg,length ,posChanged)){
		return dp[beg][length];
	}
	seen[beg][length] = 1;
	if(length == 1) return dp[beg][length] = a[beg];

	ll left = solve(beg,length/2,posChanged,!xorr);
	ll right = solve(beg+length/2,length/2,posChanged,!xorr);
	return dp[beg][length] =  xorr? left ^ right : left | right;
}

int main(){
	ll n,m,p,b;
	memset(dp,0,sizeof dp);
	memset(seen,false, sizeof seen);

	cin>>n>>m;
	ll tot = 1<<n;
	for(int i = 1; i<=tot; i++){
		cin>>a[i];
	}
	ll lastIsXor = n%2 == 0;
	solve(1,tot,-1,lastIsXor);
	for(int i = 0; i<m; i++){
		cin>>p >>b;
		a[p] = b;
		cout<< solve(1,tot,p,lastIsXor)<<"\n";
	}
}
