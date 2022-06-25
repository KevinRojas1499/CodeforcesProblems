#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t,n,z;
    cin>>t;
    while(t--){
        cin>>n>>z;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        ll M = a[0];
        for(int i = 0; i<n; i++){
            M = max(M,a[i]|z);
        }
        cout<<M<<"\n";
    }
}