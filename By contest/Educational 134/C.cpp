#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n), b(n),dmin(n),dmax(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i];
        
        ll ptrDer = n;
        for(int i = n-1; i>=0; i--){
            auto it = lower_bound(b.begin(),b.begin()+ptrDer, a[i]);
            ll idx = it-b.begin();
            dmin[i] = *it-a[i];
            dmax[i] = b[ptrDer-1]-a[i];
            if(idx == i) ptrDer = i;
        }
        for(int i = 0; i<n; i++) cout<<dmin[i]<<" ";
        cout<<"\n";
        for(int i = 0; i<n; i++) cout<<dmax[i]<<" ";
        cout<<"\n";
    }
}