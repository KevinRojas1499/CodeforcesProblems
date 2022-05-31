#include <bits/stdc++.h>
#define ll long long 

using namespace std;

vector<ll> andCount(25,0);

void add(ll a){
    for(int i = 0; i<25; i++){
        if(a&(1ll<<i)) andCount[i]++;
    }
}

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) {
        cin>>a[i];
        add(a[i]);
    }
    a.assign(n,0);
    for(int i = 0; i<25; i++){
        for(int j = 0; j<andCount[i]; j++){
            a[n-1-j]|=(1<<i);
        }
    }
    ll res = 0;
    for(int i = 0; i<n; i++){
        res+=(a[i]*a[i]);
    }
    cout<<res<<"\n";
}