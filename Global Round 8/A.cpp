# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	ll t,n,a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		c = a;
		if(a<b){
			a = b;
			b = c;
		}
		ll r  = 0;
		ll mi, ma;
		mi = b;
		ma = a;
		while(a<=n){
			b+= ma;
			r++;
			ma = b;			
			if(b>n) break;
			a+=ma;
			r++;
			ma = a;
			if(a>n) break;
			
		}
		cout<<r<<'\n';
			

	}
}

