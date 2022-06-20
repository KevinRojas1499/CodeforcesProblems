#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct FenwickTreeOneBasedIndexing {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTreeOneBasedIndexing(ll n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<ll> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            range_add(i, i, a[i]);
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }
    void add(ll idx, ll val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(ll l, ll r, ll val) {
        add(l, val);
        add(r + 1, -val);
    }

    ll point_query(ll idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> aa(n);
        for(int i = 0; i<n; i++) cin>>aa[i];
        FenwickTreeOneBasedIndexing ft(n);
        ll res = 0;
        for(int i = 0; i<n-1; i++){
            ll a = aa[i] + ft.point_query(i), b = aa[i+1]+ft.point_query(i+1);
            if(a>b) {
                res+=abs(b-a);
                ft.range_add(0,i,b-a);
            }
            else if(a < b){
                res+= abs(a-b);
                ft.range_add(i+1,n-1,a-b);
            }
        }
        // for(int i = 0; i<n; i++){
        //     cout<<aa[i]+ft.point_query(i)<<" ";
        // }
        // cout<<"Antes de offset "<<res<<" "<<ft.point_query(n)<<"\n";
        res+= abs(aa[n-1]+ft.point_query(n-1));
        cout<<res<<"\n";
    }
}