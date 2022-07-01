#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e10;

struct Data {
    ll good, open, closed;
};

class SegmentTree {
    public : 
        vector<Data> st;

        Data make_data(ll c) {
            if(c == -1) return {-1,-1,-1};
            if(c == 1) return {0,1,0};
            else return {0,0,1};
        }

        SegmentTree(vector<ll> a) {
            st.assign(a.size()*4,make_data(0));
            build(a,1,0,a.size()-1);
        }

        Data combine(Data a, Data b) {
            if(a.good == -1) return b;
            if(b.good == -1) return a;
            Data c;
            ll newGood = min(a.open,b.closed);
            c.good = a.good+b.good+newGood;
            c.open = a.open-newGood+b.open;
            c.closed = a.closed+b.closed-newGood;
            return c;
        }

        void build(vector<ll> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = make_data(a[tl]);
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }

        Data query(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return make_data(-1);
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return combine(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = make_data(val);
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = combine(st[2*v],st[2*v+1]);
            }
        }
};

int main () {
    string s;
    cin>>s;
    ll n = s.size();
    vector<ll> x(n);
    for(int i = 0; i<n; i++){
        x[i] = s[i] == '(' ? 1 : 0;
    }
    SegmentTree st(x);
    ll m;
    cin>>m;
    while(m--){
        ll a ,b;
        cin>>a>>b;
        cout<< 2*st.query(1,0,n-1, a-1,b-1).good<<"\n";

    }
}