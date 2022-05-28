#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,tot = 0;
	cin>>n;
	vector<ll> a(n);
	for(int i = 0; i<n; i++){
		cin>>a[i];
		tot+=a[i];
	}
	ll res = 0;
	if(tot%3 == 0){
		ll k = tot/3;
		vector<int> atras(n);
		ll cur = 0;
		ll cant = 0;
		for(int i = n-1; i>=0; i--){
			cur+=a[i];
			if(cur == k){
				cant++;
			}
			atras[i] = cant;
		}
		cur = 0;
		for(int i = 0; i<n; i++){
			cur+=a[i];
			if(cur == k){
				if(i+2<n) res+= atras[i+2];
			}
		}
	}
	cout<<res<<'\n';
}
