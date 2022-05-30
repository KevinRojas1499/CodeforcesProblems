#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>1 && __builtin_popcount(n) == 1){
            ll idx = 0;
            for(int i = 0; i<60; i++){
                if((1ll<<i)& n) {
                    idx = i;
                    break;
                }
            }
            if(idx%2 == 0) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else if(n%2 == 0){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }
    }
}