#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll neg = -1;
ll t,nr,ng,nb;
unsigned ll res;
vector<ll> r,g,b;

pair<ll,ll> find(ll a, vector<ll> &z){
    auto it = lower_bound(z.begin(),z.end(),a);
    if(it == z.end()){
        it--;
        return {*it,neg};
    }
    else if(it == z.begin()){
        return {neg, *it};
    }
    else{
        ll cur = *it;
        it--;
        return {*it,cur};
    }
}

unsigned ll dist(ll a, ll b, ll c){
    return (a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c);
}

void compute(vector<ll> &a, vector<ll> &bb, vector<ll> &c){
    for(int i = 0; i<(ll) a.size(); i++){
        auto [m, M] = find(a[i],bb);
        if(m != neg){
            auto [m1,M1] = find((a[i]+m)/2,c);
            if(m1 != neg) res = min(res,dist(a[i],m,m1));
            if(M1 != neg) res = min(res,dist(a[i],m,M1));
        }
        if(M != neg){
            auto [m1,M1] = find((a[i]+M)/2,c);
            if(m1 != neg) res = min(res,dist(a[i],M,m1));
            if(M1 != neg) res = min(res,dist(a[i],M,M1));
        }
    }
}
int main() {
    cin>>t;
    while(t--){
        cin>>nr>>ng>>nb;
        b.resize(nb); r.resize(nr); g.resize(ng);
        for(int i = 0; i<nr; i++) cin>>r[i];
        for(int i = 0; i<ng; i++) cin>>g[i];
        for(int i = 0; i<nb; i++) cin>>b[i];

        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());

        res = dist(r[0],g[0],b[0]);
        compute(r,b,g);
        compute(b,r,g);
        compute(b,g,r);
        compute(g,b,r);
        compute(r,g,b);
        compute(g,r,b);
        cout<<res<<"\n";
    }
}