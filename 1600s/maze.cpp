#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n,mm,k,s, c = 0;
char m[505][505];
bool seen[505][505];	
ll dx[4] = {-1,1, 0,0};
ll dy[4] = {0 ,0,-1,1};
bool in(ll x, ll y){
	return 0<=x && x<n && 0<=y && y<mm;
}
	
void dfs(ll x, ll y){
	if(c == s-k) return;
	c++;
	seen[x][y] = 1;
	for(int i = 0; i<4; i++){
		ll newX = x+dx[i];
		ll newY = y+dy[i];
		if(in(newX,newY) && !seen[newX][newY]){
			dfs(newX,newY);
		}
	}
}
	
int main(){
	cin>>n>>mm>>k;
	s = 0;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<mm; j++){
			cin>>m[i][j];
			if(m[i][j] == '.') s++;
			else seen[i][j] = 1;
		}
	}
	bool found = 0;
	for(int i = 0; i<n && !found; i++){
		for(int j = 0; j<mm; j++){
			if(m[i][j] == '.'){
				dfs(i,j);
				found = 1;
				break;
			} 
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<mm; j++){
			if(seen[i][j]) cout<<m[i][j];
			else cout<<'X';
		}
		cout<<'\n';
	}

}
