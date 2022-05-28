#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mod(ll p, ll m){
	return (p%m+m)%m;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n1,n2,n3;
	cin>>n1>>n2>>n3;
	ll n = n1+n2+n3;
	vector<ll>a(n);
	ll sum = 0;
	for(int i = 0; i<n; i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a.begin(),a.end());
	ll k = n/3;
	for(int i = 0; i<k; i++){
		sum-=2*a[i];
	}
	cout<<sum<<"\n";
}
