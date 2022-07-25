#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main () {
    ll t,n,k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<ll> M(1e5+5), a(n);
        for(int i = 0; i<n; i++) {
            cin>>a[i];
        }
        for(int i = 0; i<n; i++) {
            ll lastMax = a[i]-1;
            vector<ll> vals;
            for(int j = 1; j<= min(a[i],k); j = a[i]/(a[i]/j) + 1) {
               vals.push_back(a[i]/j);
            }
            vals.push_back(-1);
            sort(vals.begin(),vals.end());

            for(int j = 1; j<(ll) vals.size(); j++) {
                M[vals[j-1]+1] = max(M[vals[j-1]+1],vals[j]);
            }

        }
        vector<ll> accum(1e5+5);
        accum[0] = M[0];
        for(int i = 1; i<1e5+3; i++) {
            accum[i] = max(accum[i-1],M[i]);
        }
        ll res = 1e9;
        for(int i = 0; i<=a[0]; i++) {
            // cout<<i<<" "<<accum[i]<<"\n";
            res = min(res, accum[i]-i);
        }
        cout<<res<<"\n";
        

    }
}