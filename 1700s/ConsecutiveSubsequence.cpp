#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    map<ll,ll> index;
    map<ll,ll> val;
    ll longest = 1, valLong = -1;
    for(int i = 0; i<n; i++){
        val[a[i]] = val[a[i]-1]+1;
        longest = max(longest,val[a[i]]);
        if(longest == val[a[i]]) valLong = a[i];
    }
    vector<ll> res;
    for(int i = n-1; i>=0; i--){   
        if(a[i] == valLong){
            res.push_back(i+1);
            valLong--;
        } 
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<"\n";
    for(auto r : res) cout<<r<<" ";
    cout<<"\n";
}