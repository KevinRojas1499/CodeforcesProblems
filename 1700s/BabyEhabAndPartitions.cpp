#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (){
    ll n,tot = 0;
    cin>>n;
    vector<ll> a(n), power2(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        tot+=a[i];
        ll pow2 = 1, idx = 0;
        while(a[i]%pow2 == 0){
            pow2*=2;
            idx++;
        }
        power2[i] = idx;
    }
    set<ll> sums;
    sums.insert(0);
    for(int i = 0; i<n; i++){
        set<ll> q = sums;
        for(auto s : q){
            sums.insert(a[i]+s);
        }
    }
    if(tot%2 == 0 && sums.find(tot/2) != sums.end()){
        ll M = 64, pos = -1;;
        for(int i = 0; i<n; i++) {
            M = min(M,power2[i]);
            if(power2[i] == M) pos = i;
        }
        cout<<"1\n";
        cout<<pos+1<<"\n";
    
    }
    else{
        cout<<"0\n";
    }
}