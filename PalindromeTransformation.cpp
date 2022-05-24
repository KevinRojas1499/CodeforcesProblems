#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll distMod(ll a){
    if(a<13) return a;
    else return 26-a;
}

int main() {
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll res = 0;
    for(int i = 0; 2*i<n; i++){
        ll a = s[i]-'a', b = s[n-1-i]-'a';
        res+= distMod((abs(a-b)%26+26)%26);
    }
    vector<ll> path;
    p--;
    path.push_back(p);
    for(int i = 0; 2*i<n; i++){
        if(s[i] != s[n-1-i] && i!= p) {
            if(2*p<n) path.push_back(i);
            else path.push_back(n-1-i);
        }
    }
    sort(path.begin(),path.end());
    ll tot = path.back()-path[0];
    ll der = path.back()-p;
    ll izq = p-path[0];
    res+=min(tot+der,tot+izq);
    cout<<res<<"\n";
}