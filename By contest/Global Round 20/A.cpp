#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        ll cur = 1;
        for(int i = 0; i<n; i++){
            if(a[i]%2 == 0) cur = cur == 1 ? 2 : 1;
        }
        if(cur == 2) cout<<"errorgorn\n";
        else cout<<"maomao90\n";

    }
    

}