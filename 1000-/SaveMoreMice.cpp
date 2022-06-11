#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<ll> x(k);
        for(int i = 0; i<k; i++) cin>>x[i];
        sort(x.begin(),x.end());
        ll posCat = 0, res = 0;
        for(int ptrA = k-1; ptrA>=0; ptrA--){
            if(x[ptrA]<=posCat) break;
            posCat+=n-x[ptrA];
            res++;
        }
        cout<<res<<"\n";
        
    }
}