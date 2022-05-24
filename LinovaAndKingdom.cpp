#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> edges;
int seen[200005];
ll  dist[200005];
int tour[200005];
ll  happ[200005];
void dfs(ll u){
	seen[u] = 1;
	for(int i = 0; i<edges[u].size();i++){
		ll cur = edges[u][i];
		if(seen[cur]){
			continue;
		}
		dist[cur] = 1+dist[u];
		dfs(cur);
	}	
}

void dfs2(ll u){
	seen[u] = 1;
	for(int i = 0; i<edges[u].size(); i++){
		ll cur = edges[u][i];
		if(seen[cur]) continue;
		ll add = tour[u]? 1: 0;
		happ[i] = happ[u]+add;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n,k,u,v;
	cin>>n>>k;
	edges.resize(n);
	for(int i = 0; i<n-1; i++){
		cin>>u >>v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dist[0] = 0;
	dfs(0);
	
	
	vector<pair<ll,ll>> distPos(n);
	for(int i = 0; i<n; i++){
		distPos[i] = {dist[i],i};
	}
	sort(distPos.rbegin(),distPos.rend());
	ll res = 0;
	for(int i = k; i<n; i++){
		tour[distPos[i].second] = 1;
	}
	memset(seen,0,sizeof seen);
	dfs2(0);
	for(int i = 0; i<k; i++){
		cout<<distPos[i].second<<" ";
		res+=happ[distPos[i].first];
	}
	cout<<"\n";
	cout<<res<<"\n";
	
	
}
