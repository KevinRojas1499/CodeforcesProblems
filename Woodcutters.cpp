#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n, dp[100005][2];
vector<pair<ll,ll>> t;

ll solve(int i, int c){
	if(i>=n){
		return 0;
	}
	if(i == n-1){
		return 1;
	}
	if(dp[i][c] != -1) return dp[i][c];
	
	ll right = 0, left = 0;
	ll didNot = solve(i+1, 0);
	if(t[i].first+t[i].second < t[i+1].first){
		right = 1+solve(i+1,1);
	}
	ll isDown = (c == 1 ?t[i-1].second:0);
	if(i>0 && t[i].first-t[i].second > t[i-1].first+isDown){
		left =  1+solve(i+1, 0);
	}
	return dp[i][c] = max(max(left,didNot),right);
}

int main(){
	cin>>n;
	ll a,b;
	t.resize(n);
	for(int i = 0; i<n; i++){
		cin>>a>>b;
		t[i] = {a,b};		
	}
	memset(dp,-1,sizeof dp);
	cout<<1+solve(1,0)<<"\n";
}
