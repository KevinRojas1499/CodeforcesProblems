#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,q,a,b;
    cin>>n>>q;
    vector<ll> p(n), accum(n+1);
    for(int i = 0; i<n; i++) cin>>p[i];
    sort(p.rbegin(),p.rend());
    for(int i = 1; i<=n; i++){
        accum[i] = accum[i-1]+p[i-1]; 
    }
    while(q--){
        cin>>a>>b;
        cout<<accum[a]-accum[a-b]<<"\n";;
    }
}