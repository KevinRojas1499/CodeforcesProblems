#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ll t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        ll lastZero = -1,firstZero = n, muj = 0;
        for(ll i = 0; i<n; i++){
            char c;
            cin>>c;
            a[i] = c-'0';
            if(a[i] == 0) lastZero = i, firstZero = min(firstZero,i);
            else muj++;
        }
        ll inv = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 0 && i != lastZero){
                inv+=2;
            }
            if(a[i] == 1 && (i > lastZero || i< firstZero)) inv++;
        }
        cout<<max(0ll,inv-muj)<<"\n";
    }
}