#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))                    // the key operation
typedef long long ll;                            // for extra flexibility


typedef vector<ll> vll;
typedef vector<int> vi;




class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }
};

class RUPQ {                                     // RUPQ variant
private:
  FenwickTree ft;                                // internally use PURQ FT
public:
  RUPQ(int m) : ft(FenwickTree(m)) {}
  void range_update(int ui, int uj, ll v) {
    ft.update(ui, v);                            // [ui, ui+1, .., m] +v
    ft.update(uj+1, -v);                         // [uj+1, uj+2, .., m] -v
  }                                              // [ui, ui+1, .., uj] +v
  ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};



int main () {
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        RUPQ ft(2*k+10);
        
        for(int i = 0; i<n/2; i++){
            ll big = max(a[i],a[n-1-i]);
            ll small = min(a[i],a[n-1-i]);
            ll sum = a[i]+a[n-1-i];
            ft.range_update(1,sum-big,2);
            ft.range_update(sum-big+1, sum-1,1);
            ft.range_update(sum+1,sum+k-small,1);
            ft.range_update(sum+k-small+1,2*k,2);
        }
        ll res = 1e16;
        for(int i = 1; i<=2*k; i++){
            res = min(res,ft.point_query(i));
        }
        cout<<res<<"\n";
    }
}