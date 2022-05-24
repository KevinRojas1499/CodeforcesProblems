#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,sched[105],dp[105][3];

int main(){
	
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>sched[i];
		for(int j = 0; j<3; j++){
			dp[i][j] = 0;
		}
	}	
	if(sched[0] == 3 || sched[0] == 2){
		dp[0][2] = 1;
	}
	if(sched[0] == 3 ||sched[0] == 1){
		dp[0][1] = 1;
	}
	for(int i = 1; i<n; i++){
		dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3])));
		if(sched[i] == 1 || sched[i] == 3)
			dp[i][1] = 1+max(dp[i-1][0],dp[i-1][2]);
		if(sched[i] == 2 || sched[i] == 3)
			dp[i][2] = 1+max(dp[i-1][0],dp[i-1][1]);
	}
	ll res = max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	cout<<n-res<<endl;
		
}
