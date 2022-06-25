#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN = 3e5, K = 20;
int st[MAXN][K + 1], stM[MAXN][K + 1];

int lg[MAXN+1];
ll t, n;

ll getMinimum(ll L, ll R){
    int j = lg[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
ll getMaximum(ll L, ll R){
    int j = lg[R - L + 1];
    return max(stM[L][j], stM[R - (1 << j) + 1][j]);
}

ll maxIdxWithValMin(ll beg, ll end, ll targ){
    ll a = beg, b = end;
    while(a<=b){
        ll c = a+(b-a)/2;
        if(getMinimum(beg,c) == targ && (c == n-1 || getMinimum(beg,c+1) != targ)){
            return c;
        }
        else if(getMinimum(beg,c) < targ){
            b = c-1;
        }
        else {
            a = c+1;
        }
    }
    return -1;
}

ll minIdxWithValMax(ll beg, ll end, ll targ){
    ll a = beg, b = end;
    while(a<=b){
        ll c = a+(b-a)/2;
        if(getMaximum(beg,c) == targ && (c == 0 || getMaximum(beg,c-1) != targ)) {
            return c;
        }
        else if(getMaximum(beg,c) < targ){
            a = c+1;
        }
        else {
            b = c-1;
        }
    }
    return -1;
}

ll maxIdxWithValMax(ll beg, ll end, ll targ){
    ll a = beg, b = end;
    while(a<=b) {
        ll c = a+(b-a)/2;
        if(getMaximum(beg,c) == targ && (c == n-1 || getMaximum(beg,c+1) != targ)){
            return c;
        }
        else if(getMaximum(beg,c) <= targ) {
            a = c+1;
        }
        else {
            b = c-1;
        }
    }
    return -1;
}

ll minIdxWithValMin(ll beg, ll end, ll targ){
    ll a = beg, b = end;
    while(a<=b) {
        ll c = a+(b-a)/2;
        if(getMinimum(beg,c) == targ && (c == 0 || getMinimum(beg,c-1) != targ)) {
            return c;
        }
        else if(getMinimum(beg,c) <= targ){
            b = c-1;
        }
        else {
            a = c+1;
        }
    }
    return -1;
}
int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    cin>>t;
    lg[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        lg[i] = lg[i/2] + 1;
    while(t--){
        cin>>n;
        vector<ll> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        ll res = 0;

        for (int i = 0; i < n; i++){
            st[i][0] = a[i];
            stM[i][0] = a[i];

        }

        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                stM[i][j] = max(stM[i][j-1], stM[i + (1 << (j - 1))][j - 1]);

        vector<ll> next(n);
        for(int i = 0; i<n; i++){
            ll mini = maxIdxWithValMin(i,n-1,a[i]);
            ll maxi = mini == -1? -1 : minIdxWithValMax(i,mini,getMaximum(i,mini));
            next[i] = maxi;
            ll mini2 = maxIdxWithValMax(i,n-1,a[i]);
            ll maxi2 = mini2 == -1? -1 : minIdxWithValMin(i,mini2,getMinimum(i,mini2));
            next[i] = max(next[i],maxi2);
            // cout<<i<<" "<<next[i]<<"\n";
            // cout<<mini<<" "<<maxi<<" "<<mini2<<" "<<maxi2<<"\n";            
        }
        ll cur = 0;
        while(cur < n -1){
            // cout<<cur<<"\n";
            cur = next[cur];
            res++;
        }
        if(n > 1) cout<<res<<"\n";
        else cout<<"0\n";
    }
}