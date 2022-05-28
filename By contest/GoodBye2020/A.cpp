#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> tr(n);
		for(int i = 0; i<n; i++){
			cin>>tr[i];
		}
		set<ll> ar;
		for(int i = 0; i<n; i++){
			for(int j = i+1; j<n; j++){
				ar.insert(abs(tr[i]-tr[j]));
			}
		}
		cout<<ar.size()<<"\n";
	}

}
