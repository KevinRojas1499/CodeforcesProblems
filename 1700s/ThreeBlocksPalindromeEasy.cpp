#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        ll acc[n+2][27], cur[27];
        memset(acc,0,sizeof acc);
        memset(cur,0,sizeof cur);
        for(int i = 0; i<n; i++){
            cur[a[i]]++;
            for(int v = 0; v<27; v++){
                acc[i][v] = cur[v];
            }
        }
        ll res = -1;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                for(int l = 0; l<27; l++){
                    for(int k = 0; k<27; k++){
                        ll izq = min(acc[i][l],acc[n-1][l]-acc[j][l]); // min entre 0 a i y j+1 a n-1
                        ll center = acc[j][k]-acc[i][k]; //i+1 hasta j
                        if(j<n-1 && izq > 0) res = max(res,2*izq+center);
                        if(j == n-1) res = max(res,acc[n-1][l]);                       
                    }
                }

            }
        }
        cout<<res<<"\n";
    }
}
