#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll x,ll y,ll k){
	long double as= (k*(y+1)-1);
	as/=(x-1);
	ll m = (ll)ceil(as);
	//cout<<"EME "<<m<<endl;
	return m+k;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,x,y,k;
	cin>>t;
	while(t--){
		cin>>x>>y>>k;
		cout<<solve(x,y,k)<<endl;
	}
}
