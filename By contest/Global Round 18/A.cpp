#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        ll tot = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            tot+=a[i];
        }
        if(tot%n == 0) cout<<"0\n";
        else cout<<"1\n";
    }
}