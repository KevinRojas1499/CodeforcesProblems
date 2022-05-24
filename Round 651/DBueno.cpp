#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,k;
ll a[200005];
bool possible(int r, int p){
	ll cant  = 0;
	bool buscoR = !p;
	for(int i = 0; i<n; i++){
		if(buscoR){
			if(a[i]<=r){
				cant++;
				buscoR = 0;
			}
		}
		else{
			cant++;
			buscoR = 1;
		}
	}
	if(cant>=k) return 1;
	return 0;
}
			
				
			

int main(){
	cin>>n>>k;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	ll b = 0;
	ll c = 1e9;
	while(b<c){
		ll d = (b+c)/2;
		if(possible(d,0)|| possible(d,1)){
			c = d;
		}
		else{
			b = d+1;
		}
	}
	cout<<b;
}
	
