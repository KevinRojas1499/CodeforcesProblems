#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> a;
const ll INF = 1e9;

bool isLocalMinimum(ll k) {
    if(min(a[k-1], a[k+1]) > a[k]) {
        cout<<"! "<<k<<endl;
        return true;
    }
    return false;
}

void query(ll k) {
    cout<<"? "<<k<<endl;
    ll b;
    cin>>b;
    a[k] = b;
}

int main () {
    ll n;
    cin>>n;
    a.assign(n+2, INF);
    query(1);
    if(2 <=n) query(2);
    if(n-1 > 0) query(n-1);
    query(n);
    if(isLocalMinimum(1)) return 0;
    if(isLocalMinimum(n)) return 0;
    ll x = 1, y = n;
    while(x<=y) {
        ll c = x+(y-x)/2;
        if(c-1 > 0 && a[c-1] == INF) query(c-1);
        if(a[c] == INF) query(c);
        if(c+1 <=n && a[c+1] == INF) query(c+1);
        if(isLocalMinimum(c)) return 0;
        else if(a[c+1] < a[c]) {
            x = c+1;
        }
        else {
            y = c-1;
        }
    }
}