#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main () {
    ll t,n,l,r;
    cin>>t;
    while(t--) {
        cin>>n>>l>>r;
        bool possible = true;
        vector<ll> a(n+1);
        for(int i = n; i>=1; i--) {
            ll left = ceil(1.0*l/i), right = r/i;
            if(left <= right) a[i] = left*i;
            else {
                possible = false;
                break;
            } 
        }
        if(possible) {
            cout<<"YES\n";
            for(int i = 1; i<=n; i++) cout<<a[i]<<" ";
            cout<<"\n";
        }
        else {
            cout<<"NO\n";
        }
    }
}