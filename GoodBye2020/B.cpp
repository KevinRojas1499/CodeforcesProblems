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
		vector<ll> inc(n);
		map<ll,ll> count;
		for(int i = 0; i<n; i++){
			cin>>a[i];
			count[a[i]]++;
		}
		ll numChang = 1;
		while(numChang){
			numChang = 0;			
			for(int i = 0; i<n; i++){
				if(count[a[i]]>1 && !inc[i]){
					count[a[i]]--;
					count[a[i]+1]++;
					a[i]++;
					inc[i] = 1;
					numChang++;
				}
			}
		}
		set<ll> vals;
		for(int i = 0 ; i<n; i++){
			vals.insert(a[i]);
		}
		cout<<vals.size()<<"\n";
	}
		
		
}
