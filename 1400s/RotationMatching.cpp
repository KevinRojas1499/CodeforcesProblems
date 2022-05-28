#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,c;
	cin>>n;
	map<ll,ll> dist;
	for(int i = 0; i<n; i++){
		cin>>c;
		dist[c] += i;
	}
	map<ll,ll> count;
	for(int i = 0; i<n; i++){
		cin>>c;
		if(dist[c]<i){
			dist[c] = n-i+dist[c];
		}
		else{
			dist[c]-=i;
		}
		if(count.find(dist[c])== count.end()){
			count[dist[c]] = 1;
		}
		else{
			count[dist[c]]++;
		}
	}
	ll res = 0;
	for(auto [key,value]: count){
		//cout<<"Shifteo "<<key<<" con cuenta "<<value<<endl;
		res = max(res,value);
	}
	cout<<res<<endl;
	
	
	
}
