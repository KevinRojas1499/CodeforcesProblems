#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,x,n;
	cin>>t;
	while(t--){
		cin>>n>>x;
		vector<ll> a(n);
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		vector<ll> distintos;
		bool todosIguales = 1;
		bool igual = 0;
		for(int i = 0; i<n; i++){
			if(a[i]!= x){
				todosIguales = 0;
				distintos.push_back(a[i]);
			}
			if(a[i] == x){
				igual = 1;
			}
		}
		if(todosIguales){
			cout<<"0\n";
		}
		else if(igual){
			cout<<"1\n";
		}
		else{
			ll cambios = 0;
			for(int i = 0; i<(int)distintos.size(); i++){
				cambios+=(x-distintos[i]);
			}
			if(cambios == 0){
				cout<<"1\n";
			}
			else{
				cout<<"2\n";
			}
		}
	}
}
