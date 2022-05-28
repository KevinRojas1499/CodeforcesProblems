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
		vector<ll> a(n);
		vector<bool> v(n), m(n);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		ll change = -1;
		ll inti = 0;
		for(int i = 1; i<n-1; i++){
			if(a[i-1]<a[i] && a[i]>a[i+1]){
				m[i] = 1;
				inti++;
			}
			else if(a[i-1]>a[i] && a[i]<a[i+1]){
				v[i] = 1;
				inti++;
			}
		}
		for(ll i = 1; i<n-1; i++){
			if(v[i] || m[i]){
				ll cur = a[i];
				a[i] = a[i-1];
				ll changes1 = 0;
				for(ll j = max(i-8,(ll)1); j<min(i+8,n-1); j++){
					if(v[j]||m[j]){
						changes1++;
					}
					if(a[j-1]<a[j] && a[j]>a[j+1]){
						changes1--;
					}
					else if(a[j-1]>a[j] && a[j]<a[j+1]){
						changes1--;
					}
				}
				a[i] = a[i+1];
				ll changes2 = 0;
				for(ll j = max(i-8,(ll)1); j<min(i+8,n-1); j++){
					if(v[j]||m[j]){
						changes2++;
					}
					if(a[j-1]<a[j] && a[j]>a[j+1]){
						changes2--;
					}
					else if(a[j-1]>a[j] && a[j]<a[j+1]){
						changes2--;
					}
				}
				a[i] = cur;
				change = max(change,max(changes1,changes2));
			}
		}
		ll res = inti-change;
		if(change == -1){
			res = inti;
		}
		cout<<res<<"\n";
			
	}
}
