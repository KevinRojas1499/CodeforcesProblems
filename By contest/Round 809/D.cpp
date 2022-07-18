#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> a;
ll t,n,k;


ll solve(ll m) {
    ll mm = 1e9, MM = -1;
    for(int i = 0; i<n; i++) {
        ll p = a[i]/m;
        if(p == 0) p++;
        p = min(p,k);
        mm = min(mm,a[i]/p);
        MM = max(MM,a[i]/p);
    }
    return MM-mm;
}

int main () {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        a.resize(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        ll best = 1e9;
        for(int i = 1; i<=3000; i++) {
            best = min(best,solve(i));
        }
        cout<<best<<"\n";
    }
}