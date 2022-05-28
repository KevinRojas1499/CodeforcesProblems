#include<bits/stdc++.h>
#define ll long long
using namespace std;

int hard[200005];


int dp[200005][2];


ll solve(int n,int pos,int amigo){
	if(pos>=n){
		return 0;
	}
	if(dp[pos][amigo] != -1){
		return dp[pos][amigo];
	}
	ll res = 0;
	if(pos == n-1 && amigo){
		if(hard[pos]) return 1;
		else return 0;
	}
	else if(pos == n-1 && !amigo){
		return 0;
	}
	if(amigo){
		if(hard[pos]){
			res++;			
			ll k = hard[pos+1]?1:0;
			res+= min(solve(n,pos+1,0),k+solve(n,pos+2,0));
			
		}
		else{
			ll k = hard[pos+1]?1:0;				
			res+=min(solve(n,pos+1,0),k+solve(n,pos+2,0));
			
		}
	}
	else{
		res+=min(solve(n,pos+1,1),solve(n,pos+2,1));
	}
	return dp[pos][amigo] = res;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,n;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i = 0; i<n; i++){
			cin>>hard[i];
			dp[i][0] = -1;
			dp[i][1] = -1;
		}
		cout<<solve(n,0,1)<<endl;
	}
}
