#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    ll t,p,f,ns,nw,s,w;
    cin>>t;
    while(t--){
        cin>>p>>f;
        cin>>ns>>nw;
        cin>>s>>w;
        if(s > w){
            swap(s,w);
            swap(ns,nw);
        }
        ll res = -1;
        for(ll i = 0; i<=ns; i++){
            ll cantSP = min(i,p/s);
            ll rest = p-cantSP*s;
            ll cantWP = min(nw,rest/w);
            ll cantSF = min(ns-i,f/s);
            ll rest2 = f-cantSF*s;
            ll cantWF = min(nw-cantWP,rest2/w); 
            // cout<<cantSP<<" "<<cantWP<<"\n";
            // cout<<cantSF<<" "<<cantWF<<"\n";
            res = max(res, cantSP+cantWP+cantSF+cantWF);
        }
        cout<<res<<"\n";
    }
}