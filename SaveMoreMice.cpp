#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<ll> a(k);
        for(int i = 0; i<k;i++) cin>>a[i];
        sort(a.begin(),a.end());

        ll cat = 0;
        ll mouse = k-1;
        ll res = 0;
        while(cat < n){
            if(a[mouse]<=cat) break;
            a[mouse];
            cat+= n-a[mouse];
            mouse--;
            res++;
        }
        cout<<res<<"\n";
    }
}