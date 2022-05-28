#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m;
vector<vector<int>> edges;
int cats[100005];
int seen[100005];
int res = 0;

void dfs(int k,int cat){
	seen[k] = 1;
	if(cat > m){
		return ;
	}
	if(edges[k].size() == 1 && k!= 1){
		res++;
		return;
	}
	for(auto i: edges[k]){
		if(!seen[i]){
			int val = (cats[i] == 1? cat+1 : 0);
			dfs(i,val);
		}
	}
}


int main(){
	ll c,u,v;
	cin>>n>>m;
	edges.resize(n+1);
	for(int i = 0; i<n; i++){
		cin>>c;
		cats[i+1] = c;
	}
	for(int i = 0 ; i < (n-1); i++){
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,cats[1]);
	cout<<res<<"\n";
	
}
