#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while (t--){
        cin>>n;
        vector<ll> a(n), b(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b.begin(),b.end());
        bool possible = false;
        for(int i = 0; i<n; i++){
            if(a[i] != b[i]) possible = true;
        }
        if(possible){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    

}