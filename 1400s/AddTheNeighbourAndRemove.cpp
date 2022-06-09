#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll current = 0;
bool possible(vector<ll> &a, ll start, ll target){
    ll tot = 0;
    if(start>(ll)a.size()) return false;
    int i = start;
    for(i = start; i<(ll) a.size(); i++){
        tot+=a[i];
        if(tot>= target) break;
    }
    if(i == (ll) a.size() && tot<target) return false;
    if(tot == target && i != (ll) a.size()-1){
        // cout<<"Inside "<<start<<" "<<i<<" "<<target<<" "<<tot<<"\n";
        current+=(i-start);
        return possible(a,i+1,target);
    }
    else if( tot == target){
        current+=(i-start);
        return true;
    }
    else{
        return false;
    }
}

int main (){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];

        ll cur = 0;
        ll res = n-1;
        for(int i = 0; i<n; i++){
            current = 0;
            cur+=a[i];
            if(possible(a,i+1,cur)){
                // cout<<"Possible con "<<cur<<" "<<current<<"\n";
                res = min(res,i+current);
            }
        }
        cout<<res<<"\n";
    }
}