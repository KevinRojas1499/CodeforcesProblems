#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,n;
	cin>>n;
	vector<ll>a(n);
	for(int i= 0; i<n; i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	vector<ll> b(n);
	for(int i = 0; i<n/2; i++){
		b[2*i] = a[n-n/2+i];
		b[2*i+1] = a[i];
	}
	if(n%2==1){
		b[n-1] = a[n/2];
	}
	ll res = 0;
	for(int i = 1; i<n-1; i++){
		if(b[i]<b[i-1] && b[i]<b[i+1]){
			res++;
		}
	}
	cout<<res<<endl;
	for(int i = 0; i<n/2; i++){
		cout<<a[n-n/2+i]<<" "<<a[i]<<" ";
	}
	if(n%2==1){
		cout<<a[n/2]<<endl;
	}
}
