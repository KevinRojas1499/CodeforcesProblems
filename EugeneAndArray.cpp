#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    ll n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i = 1; i<=n; i++) cin>>a[i];
    vector<ll> accum(n+1);
    for(int i= 1; i<=n; i++) accum[i] = accum[i-1]+a[i];
    map<ll,vector<ll>> nexts;

    for(int i = 1; i<=n; i++) nexts[accum[i]].push_back(i);
    
    ll res = 0;
    set<ll> currents;
    ll last = 0;
    currents.insert(0);
    for(int i = 1; i<=n; i++){
        for(int j = last+1; j<=n; j++){
            if(currents.find(accum[j]) != currents.end()){
                break;
            }
            else{
                currents.insert(accum[j]);
                last = j;
            }
        }
        res+=currents.size()-1;
        currents.erase(accum[i-1]);
    }
    cout<<res<<"\n";
}
