#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
    ll u,v;
    cin>>u>>v;

    if(u>v) cout<<"-1\n";
    else{
        ll d = v-u;
        vector<ll> count(64);
        for(int i = 0; i<=60; i++) if(u&(1ll<<i)) count[i] = 1;
        bool possible = true;
        for(int i = 60; i>=0; i--){
            if(d&(1ll<<i)) {
                if(i>0) count[i-1]+=2;
                else possible = false;
            }
        }
        if(!possible) cout<<"-1\n";
        else{
            ll m = -1;
            vector<ll> res;
            for(int i = 0; i<62; i++){
                m = max(m,count[i]);
            }
            res.resize(m);
            for(int i = 0; i<62; i++){
                for(int j = 0; j<count[i]; j++){
                    res[j]|=(1ll<<i);
                }
            }
            cout<<m<<"\n";
            for(auto a : res) cout<<a<<" ";
            if(m>0) cout<<"\n";
        }
    }
}