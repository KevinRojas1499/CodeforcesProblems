#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool possible = false;
        for(int i = 0; i<40; i++){
            ll y = (n-3*i)/7;
            if(y>=0 && 3*i+7*y == n) possible = true;
        }
        if(possible) cout<<"YES\n";
        else cout<<"NO\n";
    }
}