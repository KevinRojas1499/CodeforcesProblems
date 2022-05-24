#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        for(int i = n-1; i>=0; i--){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}