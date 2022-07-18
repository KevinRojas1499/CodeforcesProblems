#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main () {
    ll t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        vector<char> s(m+1,'B');
        for(int i = 0; i<n; i++ ) {
            ll rev = m+1-a[i];
            if(rev < a[i] && s[rev] == 'B') s[rev] = 'A';
            else if(s[a[i]] == 'A') s[rev] = 'A';
            else s[a[i]] = 'A';
        }
        for(int i = 1; i<=m; i++) cout<<s[i];
        cout<<"\n";
    }
}