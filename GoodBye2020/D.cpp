#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll t,n,u,v;
	cin>>t;
	while(t--){
		cin>>n;
		vector<ll> w(n);
		vector<ll> deg(n);
		ll tot = 0;
		for(int i = 0; i<n; i++){
			cin>>w[i];
			tot+=w[i];
		}
		for(int i = 0; i<n-1; i++){
			cin>>u>>v;
			u--;v--;
			deg[u]++;
			deg[v]++;			
		}
		priority_queue<ll> nodes;
		for(int i = 0; i<n; i++){
			if(deg[i]>1)
				for(int j = 0; j<deg[i]-1; j++)
					nodes.push(w[i]);
		}
		for(int i = 0; i<n-1; i++){
			cout<<tot<<" ";
			if(nodes.empty()) continue;
			tot+=nodes.top();
			nodes.pop();
		}
		cout<<"\n";
	}
}
