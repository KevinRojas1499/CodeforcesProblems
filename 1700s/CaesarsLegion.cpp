#include <bits/stdc++.h>
# define ll long long 
using namespace std;

const int N = 105;
const int MOD = 1e8;
ll n1,n2,k1,k2;

ll dp[N][N][2];

ll solve(ll n,ll m,ll cab){
	if(dp[n][m][cab] != -1)
		return dp[n][m][cab];
	dp[n][m][cab] = 0;
	if(cab){
		if(m == 0 ){
			return dp[n][m][cab] = 0;
		}
		if(n == 0 && m<= k2){
			return dp[n][m][cab] = 1;
		}
		for(int i = 1; i<= min(m,k2);i++){
			dp[n][m][cab] += solve(n,m-i,0);
			dp[n][m][cab]%=MOD;
		}
		return dp[n][m][cab];
	}
	else{
		if(n == 0)
			return 0;
		if(m == 0 && n<= k1){
			return dp[n][m][cab] = 1;
		}
		for(int i = 1; i<=min(n,k1); i++){
			dp[n][m][cab] += solve(n-i,m,1);
			dp[n][m][cab]%=MOD;
		}
		return dp[n][m][cab];
	}
	
}
		

int main(){
	cin>>n1>>n2>>k1>>k2;
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			for(int k = 0; k<2; k++)
				dp[i][j][k] = -1;
	solve(n1,n2,0);
	solve(n1,n2,1);
	cout<< (dp[n1][n2][0]+dp[n1][n2][1])%MOD<<'\n';
}
