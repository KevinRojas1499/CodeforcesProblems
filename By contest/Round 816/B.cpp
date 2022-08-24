#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t,n,k,b,s;
    cin>>t;
    while(t--){
        cin>>n>>k>>b>>s;
        if(k*b > s) {
            cout<<"-1\n";
            continue;
        }
        vector<ll> a(n);
        ll curB = 0, curS = 0;
        if(s/k == b) {
            a[0] = s;
            for(auto x : a) cout<<x<<" ";
            cout<<"\n";
            continue;
        }
        a[0] = k*(b+1)-1;
        curS = a[0], curB = b;
        for(int i = 1; i<n; i++){
            if(curB == b && curS == s) break;
            for(int j = min(k-1,s-curS); j>=0; j--){
                if(curS+j <=s) {
                    a[i] = j;
                    curS+=j;
                    break;
                }
            }
        }
        if(curB == b && curS == s) {
            for(auto x : a) cout<<x<<" ";
            cout<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
}