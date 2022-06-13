#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        ll ones = 0;
        for(int i = 0; i<n; i++) {
            cin>>a[i];
            if( i> 0 && i != n-1 && a[i] == 1) ones++;
        }
        if((n == 3 && a[1]%2 != 0) || ones == n-2) {
            cout<<"-1\n";
            continue;
        }
        
        ll res = 0;
        for(int i = 1; i<n-1; i++){
            if(a[i]%2 == 0) res+= a[i]/2;
            else res+=(a[i]+1)/2;
        }
        cout<<res<<"\n";
    }
}