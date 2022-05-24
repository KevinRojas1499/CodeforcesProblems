#include<bits/stdc++.h>
#define ll long long	

using namespace std;
ll k;
const ll MOD = 1e9+7;
const ll MAXN = 100005;

ll dp[MAXN];
ll pref[MAXN];


int main(){
	ll t,a,b;
	cin>>t>>k;
	for(int i = 0; i<k;i++){
		dp[i] = 1;
	}
	for(int i = k; i<MAXN;i++){
		dp[i] = (dp[i-1]+dp[i-k])%MOD;
	}
	for(int i  = 0; i<MAXN; i++){
		pref[i]=pref[i-1]+dp[i];
		pref[i]%=MOD;
	}
		
	while(t--){
		cin>>a>>b;
		cout<<((pref[b]-pref[a-1])+MOD)%MOD<<endl;
	}
}
