#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main () {
    ll t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<ll> c(n), res(n+1);
        vector<vector<ll>> idxEven(n+1), idxOdd(n+1);
        for(int i = 0; i<n; i++) {
            cin>>c[i];
            if(i%2 == 0) idxEven[c[i]].push_back(i);
            else idxOdd[c[i]].push_back(i);
        }
        for(int i = 1; i<=n; i++) {
            ll best = 0;
            ll even = 0, odd = 0;
            ll cur = -1;
            if(idxEven[i].size() > 0) cur = idxEven[i][0];
            if(idxOdd[i].size() > 0) {
                if(cur == -1 || cur > idxOdd[i][0]) cur = idxOdd[i][0]; 
            }
            if(cur == -1) {
                continue;
            }
            else {
                best = 1;
            }
            while(even < (ll) idxEven[i].size() && odd < (ll) idxOdd[i].size()) {
                if(cur%2 == 0) {
                    while(odd < (ll) idxOdd[i].size()) {
                        if(idxOdd[i][odd] < cur) odd++;
                        else {
                            cur = idxOdd[i][odd];
                            best++;
                            break;
                        }
                    }
                }
                else {
                    while(even < (ll) idxEven[i].size()) {
                        if(idxEven[i][even] < cur) even++;
                        else {
                            cur = idxEven[i][even];
                            best++;
                            break;
                        }
                    }
                }
            }
            res[i] = best;
        }
        for(int i = 1; i<=n ;i++) cout<<res[i]<<" ";
        cout<<"\n";

    }
}