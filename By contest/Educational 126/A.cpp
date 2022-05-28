#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n), b(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i];
        
        for(int i = 1; )
        ll res = 0;
        for(int i = 1; i<2*n; i++){
            ll valA = abs(a[i-1]-a[i]) + abs(a[i]-a[i+1]);
            ll valB = abs(b[i-1]-b[i]) + abs(b[i]-b[i+1]);
            res+=(valA+valB);
        }
        ll valA = abs(a[0]-a[1]) + abs(b[0]-b[1]);
        ll valB = abs(a[n-2]-a[n-1]) + abs(b[n-2]-b[n-1]);
        res-= (valA+valB);
        res/=2;
        res+=(valA+valB);
        cout<<res<<"\n";

    }

}