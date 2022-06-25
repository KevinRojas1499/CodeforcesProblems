#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t, n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        cin>>k;
        vector<ll> b(k);
        for(int i = 0; i<k; i++) cin>>b[i];
        
        bool canTransform = true;
        vector<pair<ll,ll>> decompA, decompB;
        for(int i = 0; i<n; i++){
            ll count = 1;
            while(a[i]% m == 0){
                a[i]/=m;
                count*=m;
            }
            if(decompA.size() > 0 && decompA.back().first == a[i]){
                decompA.back().second+=count;
            }
            else {
                decompA.push_back({a[i],count});
            }
        }
        for(int i = 0; i<k; i++){
            ll count = 1;
            while(b[i]% m == 0){
                b[i]/=m;
                count*=m;
            }
            if(decompB.size() > 0 && decompB.back().first == b[i]){
                decompB.back().second+=count;
            }
            else {
                decompB.push_back({b[i],count});
            }
        }
        for(int i = 0; i<(ll) min(decompA.size(),decompB.size()); i++){
            // cout<<decompA[i].first<<" "<<decompA[i].second<<" "<<decompB[i].first<<" "<<decompB[i].second<<"\n";
            if(decompA[i].first != decompB[i].first || decompA[i].second != decompB[i].second){
                canTransform = false;
            }
        }
        if(canTransform && decompA.size() == decompB.size()){
            cout<<"Yes\n";
        }
        else {
            cout<<"No\n";
        }
    }
}