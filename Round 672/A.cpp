#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
	ll tt,n;
	
	cin>>tt;
	while(tt--){
		cin>>n;
		vector<ll> a(n);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		ll count = 0;
		for(int i = 0; i<n-1; i++){
			if(a[i]>a[i+1]){
				count++;
			}
		}
		if(count!=n-1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
	
