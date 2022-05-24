#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    ll CHANGED = -1;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        ll res = 0, last = -1;
        for(int i = 0; i<n-1; i++){
            if(a[i] == a[i+1]) last = i;
        }

        for(int i = 0; i<last; i++){
            if(a[i] == a[i+1]){
                if(i+1 == last && a[i+1] == CHANGED) {
                    continue;
                }
                a[i+1] = CHANGED;
                if(i+2<n) a[i+2] = CHANGED;
                res++;
                
            }
        }
        cout<<res<<"\n";
    }
}