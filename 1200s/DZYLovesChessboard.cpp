#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 105;
ll n,m;
char mat[mxN][mxN], res[mxN][mxN];
bool seen[mxN][mxN];

ll dx[4] = {0,0,1,-1};
ll dy[4] = {1,-1,0,0};

bool isIn(ll a, ll b){
    return 0<=a && a<n && 0<=b && b<m;
}

void dfs(ll a, ll b, char color){
    if(seen[a][b]) return;
    seen[a][b] = 1;
    res[a][b] = color;
    for(int i = 0; i<4; i++){
        ll x = a+dx[i], y = b+dy[i];
        if(isIn(x,y) && mat[x][y] == '.') {
            char other = color == 'B' ? 'W' : 'B';
            dfs(x,y,other);
        }
    }
}

int main (){
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>mat[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == '-'){
                res[i][j] = '-';
                continue;
            }
            dfs(i,j,'W');
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<res[i][j];
        }
        cout<<"\n";
    }
}