#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> a(n);
		vector<pair<ll,ll>> ordered(n);
		vector<ll> locked(n);
		for(int i = 0 ; i<n; i++){
			cin>>a[i];
			ordered[i] = {a[i],i};
		}
		for(int i = 0; i<n; i++){
			cin>>locked[i];
		}
		vector<ll>res;
		for(int i = 0; i<n; i++){
			if(!locked[i]){
				res.push_back(a[i]);
			}
		}
		sort(res.rbegin(),res.rend());
		for(int i=  0; i<n; i++){
			if(locked[i]){
				res.insert(res.begin()+i,a[i]);
			}
		}
		for(int i = 0; i<n; i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}
