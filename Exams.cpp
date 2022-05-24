#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,t,a,b;
	cin>>n;
	vector<pair<ll,ll>> ex(n);
	for(int i = 0; i<n; i++){
		cin>>a>>b;
		ex[i] = {a,b};
	}
	sort(ex.begin(),ex.end());
	ll res = ex[0].second;
	for(int i = 0; i<n; i++){
		if(ex[i].second>=res){
			res = ex[i].second;
		}
		else{
			res = ex[i].first;
		}
	}
	cout<<res<<endl;
}
