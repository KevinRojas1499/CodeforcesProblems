#include <bits/stdc++.h>
#define ll long long

using namespace std;

set<ll> erased;

bool possible(string &a, string &b){
    ll k = 0;
    for(int i = 0; i< (ll) b.size() && k< (ll) a.size(); i++){
        if(erased.find(i) != erased.end()) continue;
        if(a[k] == b[i]) k++;
    }
    return k == (ll) a.size();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1,s2;
    cin>>s1>>s2;
    ll n = s1.size();
    vector<ll> p(n);
    for(int i = 0; i< n; i++) cin>>p[i];

    int a = 0, b = n-1;
    while(a<=b){
        ll c = a+(b-a)/2;
        erased.clear();
        for(int i = 0; i<c; i++) erased.insert(p[i]-1);
        if(!possible(s2,s1)) b = c-1;
        else a = c+1;
    }
    cout<<b<<"\n";


}