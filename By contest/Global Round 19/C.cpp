#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        ll impares = 0, imparesTotales = 0, paresTotales = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = 1; i<n-1; i++){
            if(a[i] %2 == 0){
                paresTotales+=a[i];
            }
            else{
                impares++;
                imparesTotales+=a[i];
            }
        }
        if(paresTotales>=impares){
            ll res = (imparesTotales+impares)/2;
            res+= paresTotales/2;
            cout<<res<<'\n';
        }
        else{
            cout<<"-1\n";
        }

    }
    
}