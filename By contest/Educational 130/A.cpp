#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        ll curEnergy = m, need = 0;
        for(int i = 0; i<n; i++){
            if(curEnergy>= a[i]){
                curEnergy-=a[i];
            }
            else{
                need+=(a[i]-curEnergy);
                curEnergy = 0;
            }
        }
        cout<<need<<"\n";
    }
}