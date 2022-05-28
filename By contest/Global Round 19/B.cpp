#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        ll cost [n+2][n+2];
        ll res = 0;
        memset(cost,0,sizeof cost);
        for(int i = 0; i<n; i++){
            cin>>a[i];
            cost[i][i] = a[i] ? 1: 2;
            res+=cost[i][i];
        }
        for(int l = 2; l<=n; l++){
            for(int i = 0; i<n; i++){
                ll j = i+l-1;
                if(j>=n) break;
                set<ll> nums;
                for(int k = i;k<=j; k++) nums.insert(a[k]);
                cost[i][j]++;
                for(int k = 0; k<=l+1; k++){
                    if(nums.find(k) == nums.end()){
                        cost[i][j] += k;
                        break;
                    }
                }
                for(int k = i; k<j; k++){
                    cost[i][j] = max(cost[i][j],cost[i][k]+cost[k+1][j]);
                }
                res+=cost[i][j];
      
            }
        }

        cout<<res<<"\n";
    }



    
}