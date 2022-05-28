#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod(ll p, ll m){
	return (p%m+m)%m;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll val = 1;
		for(int i = 0; i<n; i++){
			cout<<mod(8+abs(val-i),10);			
		}
		cout<<"\n";	
		
	}
}
