#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e11+5;

int main(){
	ll n,m,u,v,w;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> edges(n);
	vector<ll> dist(n,INF);
	
	for(int i = 0; i<m; i++){
		cin>>u>>v>>w;
		u--;v--;
		edges[u].push_back({v,w});
		edges[v].push_back({u,w});
	}
	dist[0] = 0;
	
	vector<ll> ancestor(n);
	set< pair<ll,ll>> edg;
	for(int i = 0; i<n; i++){
		edg.insert({dist[i],i});
	}
	while(!edg.empty()){
		auto [d,a] =  *edg.begin();
		edg.erase(edg.begin());
		for(auto &[b,c]: edges[a]){
			if(dist[b] > dist[a]+c){
				edg.erase(edg.find({dist[b],b}));
				dist[b] = dist[a]+c;
				ancestor[b] = a;
				edg.insert({dist[b],b});
			}
			
		}
		
	}
	if(dist[n-1] == INF){
		cout<<"-1\n";
	}
	else{
		ll cur = n-1;
		vector<ll> path;
		while(cur){
			path.push_back(cur+1);
			cur = ancestor[cur];
		}
		path.push_back(1);
		for(auto a = path.end()-1; a>= path.begin(); a--){
			cout<<(*a)<<" ";
		}
		cout<<"\n";
	}
		

}

