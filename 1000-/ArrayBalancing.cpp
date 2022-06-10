#include <bits/stdc++.h>
#define ll long long

using namespace std;

void exchange(vector<ll> &a, vector<ll> &b, ll i){
    ll temp = a[i];
    a[i] = b[i];
    b[i] = temp;
}

int main (){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n),b(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i];

        for(int i = 1; i<n; i++){
            if(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]) > abs(b[i]-a[i-1])+abs(a[i]-b[i-1])){
                for(int j = i; j<n; j++) exchange(a,b,j);
            }
        }
        ll res = 0;
        for(int i = 1; i<n; i++){
            res+= abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
        }
        cout<<res<<"\n";
    }
}