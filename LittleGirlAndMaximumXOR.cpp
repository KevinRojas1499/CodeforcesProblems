#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    ll l,r;
    cin>>l>>r;
    ll a = r, firstIdx = -1;
    for(int i = 60; i>=0; i--){
        ll bit = 1ll<<i;
        if((l&bit) != (r&bit)){
            firstIdx = i;
            break;
        }
    }
    for(int i = firstIdx; i>=0; i--){
        ll bit = 1ll<<i;
        ll x = l&bit, y = r&bit;
        if(x && y) a^=bit;
        if(!x && !y) a|=bit;
    }
    cout<<(l^a)<<"\n";
}