#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main () {
    ll n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        ll b = a[0];
        bool possible = true;
        for(int i = 1; i<n; i++) {
            if(a[i]%b != 0) possible = false; 
        }
        if(possible) cout<<"YES\n";
        else cout<<"NO\n";
    }
}