#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll process(vector<ll> &t){
	ll res = 0;
	for(int i = 0; i<t.size(); i++){
		if(t[i]){
			res+= (1<<i);
		}
	}
	return res;
}

void add(vector<ll> &t, int a, int add){
	for(int j = 0; j<32; j++){
		if( a & 1<<j){
			if(add) t[j]++;
			else t[j]--;
		}
	}	
}
int main(){
	ll n,m,a,p,b;
	
	cin>>n>>m;
	
	vector<ll> total(33,0);
	vector<ll> vals(1<<n);
	for(int i= 0; i< 1<<n; i++){
		cin>>vals[i];
		add(total,vals[i],1);

	}
	
	for(auto x: total){
		cout<<x<<" ";
	}
	cout<<"\n";
	
	for(int i = 0; i<m; i++){
		 cin>>p>>b;
		 add(total,vals[i],0);
		 add(total,b,1);
		 vals[i] = b;
		 cout<<process(total)<<"\n";
	 }
	 	 

}
