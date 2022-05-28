# include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
	ll t,n;
	string a,b;
	cin>>t;
	while(t--){
		cin>>b;
		n = b.size();
		a = "";
		for(int i = 0; i<n; i+=2){
			a+=b[i];
		}
		a+=b[n-1];
		cout<<a<<'\n';
	}
}

