#include <bits/stdc++.h>
#define ll long long
#define LSOne(S) ((S) & -(S))

using namespace std;

int main () {
    ll n,q,t;
    cin>>t;
    while(t--) {
        cin>>n>>q;
        vector<ll> a(n), res(n,0);
        for(int i = 0; i<n; i++) cin>>a[i];
        ll currentIq = 0;
        for(int i = n-1; i>=0; i--) {
            if(a[i] <= currentIq) res[i] = 1;
            else if(currentIq < q) {
                res[i] = 1;
                currentIq++;
            }
        }
        for(auto c : res) cout<<c;
        cout<<"\n";
    }
}