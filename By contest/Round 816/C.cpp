#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Data {
    ll totSubseq, len, izq, der, bDer, bIzq, posIn;
};


vector<ll> a;


struct SegmentTree {
    vector<Data> st;
    ll n;

    Data make_data(ll aa, ll pos){
        Data m;
        m.totSubseq = 1;
        m.len = 1;
        if(aa == -1) m.len = 0;
        m.izq = aa;
        m.der = aa;
        m.posIn = pos;
        m.bDer = m.bIzq = 1;
        return m;
    }

    void modifyArrays(Data& m, const Data &izq, const Data &der) {
        m.len = izq.len+der.len;
        ll curBeauty = 1;
        m.bIzq = 0;
        for(int i = m.posIn; i<m.posIn+m.len; i++) {
            if(i > m.posIn && a[i] != a[i-1]) curBeauty++;
            m.bIzq+= curBeauty;
        }
        curBeauty = 1;
        m.bDer = 0;
        for(int i = m.len-1+m.posIn; i>=m.posIn; i--) {
            if(i < m.len-1+m.posIn && a[i] != a[i+1]) curBeauty++;
            m.bDer+= curBeauty;
        }

        m.izq = a[m.posIn];
        m.der = a[m.posIn+m.len-1];
    }
    
    Data combine(const Data &izq, const Data &der) {
        Data m;
        if(izq.der == -1) {
            m = der;
            return m;
        }
        if(der.der == -1) {
            m = izq;
            return m;
        }
        
        ll totBeautyIzq = izq.bDer, totBeautyDer = der.bIzq;
        m.totSubseq = izq.totSubseq+der.totSubseq;

        if(izq.der != der.izq) m.totSubseq+= izq.len*totBeautyDer+der.len*totBeautyIzq;
        else m.totSubseq+= izq.len*totBeautyDer+der.len*(totBeautyIzq-izq.len);
        
        m.izq = izq.izq;
        m.der = der.der;

        modifyArrays(m,izq,der);

        return m;
    }
    SegmentTree(vector<ll> aa) {
        n = aa.size();
        st.resize(n*4);
        build(aa,1,0,n-1);
    }
    void build(vector<ll> &aa, ll v, ll tl, ll tr) {
        if(tl == tr) {
            st[v] = make_data(aa[tl], tl);
        }
        else {
            ll tm = tl+(tr-tl)/2;
            build(aa,2*v,tl,tm);
            build(aa,2*v+1,tm+1,tr);
            st[v] = combine(st[2*v],st[2*v+1]);
        }
    }
    Data query(ll v, ll tl, ll tr, ll l, ll r){
        if(l > r) return make_data(-1, -1);
        if(tl == l && tr == r) return st[v];
        ll tm = tl + (tr-tl)/2;
        return combine(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
    }
    Data query(ll l, ll r){
        return query(1,0,n-1,l,r);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll val){
        if(tl == tr) {
            st[v] = make_data(val, tl);
        }
        else {
            ll tm = tl+(tr-tl)/2;
            if(pos<= tm) update(2*v,tl,tm,pos,val);
            else update(2*v+1,tm+1,tr,pos,val);
            st[v] = combine(st[2*v],st[2*v+1]);
        }
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,m,k,x;
    cin>>n>>m;
    a.resize(n);
    for(int i = 0; i<n; i++) cin>>a[i];

    SegmentTree st(a);
    cout<<"BUILD"<<endl;
    for(int i = 0; i<m; i++){
        cin>>k>>x;
        st.update(1,0,n-1,k-1,x);
        Data d = st.query(0,n-1);
        cout<<d.totSubseq<<"\n";
    }
}