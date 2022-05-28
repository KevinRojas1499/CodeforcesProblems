#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,x;
	cin>>t;
	while(t--){
		cin>>x;
		ll n = 1;
		ll res = 0;
		while(x>=0){
			x-=(n*(n+1)/2);
			n= 2*n+1;
			res++;
		}
		cout<<res-1<<endl;
	}
}
