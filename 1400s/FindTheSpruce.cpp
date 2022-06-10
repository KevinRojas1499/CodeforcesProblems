#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t,n,m;
const ll mxN = 505;
char mat[mxN][mxN];
ll dp[mxN][mxN][2];

int main (){
    cin>>t;
    while(t--){
        cin>>n>>m;

        memset(dp,0,sizeof dp);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        ll res = 0;
        for(int k = 0; k<n; k++){
            for(int a = 0; a<m; a++){
                for(int b = a; b<m; b++){
                    if(mat[k][b] == '.') break;
                    if(a == b) {
                        dp[a][b][1] = 1;
                        res++;
                    }
                    if(a+1 <= b-1 && k>0 && a+1<m && b-1>=0){
                        dp[a][b][1] = dp[a+1][b-1][0];
                        res+=dp[a][b][1];
                        // cout<<"Fila "<<k<<" "<<a<<" "<<b<<" "<<dp[a][b][k]<<"\n";
                    } 
                }
            }
            for(int a = 0; a<m; a++){
                for(int b = a; b<m; b++){
                    dp[a][b][0] = dp[a][b][1];
                    dp[a][b][1] = 0;
                }
            }
        }
        cout<<res<<"\n";
        
    }

}