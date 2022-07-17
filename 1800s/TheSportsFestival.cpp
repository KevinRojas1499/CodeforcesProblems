#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct SparseTableMin{
    //Modificar f con la funcion asociativa e idempotente buscada
    vector<vector<ll>> st;
    vector<ll> lg;
    ll N,K; //K = log_2(N)
    void build(vector<ll> a) {
        N = a.size(), K = 25;
        st.resize(N+5,vector<ll> (K));
        lg.resize(N+5);
        for (int i = 0; i < N; i++)
            st[i][0] = a[i];
            
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

        lg[1] = 0;
        for (int i = 2; i <= N; i++)
            lg[i] = lg[i/2] + 1;
    }
    ll get(ll L, ll R) { //para minimo
        int j = lg[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

struct SparseTableMax{
    //Modificar f con la funcion asociativa e idempotente buscada
    vector<vector<ll>> st;
    vector<ll> lg;
    ll N,K; //K = log_2(N)
    void build(vector<ll> a) {
        N = a.size(), K = 25;
        st.resize(N+5,vector<ll> (K));
        lg.resize(N+5);
        for (int i = 0; i < N; i++)
            st[i][0] = a[i];
            
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

        lg[1] = 0;
        for (int i = 2; i <= N; i++)
            lg[i] = lg[i/2] + 1;
    }
    ll get(ll L, ll R) { //para minimo
        int j = lg[R - L + 1];
        return max(st[L][j], st[R - (1 << j) + 1][j]);
    }
};
		
const ll mxN = 2005;
ll n;
SparseTableMin stMin;
SparseTableMax stMax;
vector<ll> a;
ll dp[mxN][mxN], seen[mxN][mxN];

ll solve(ll l, ll r) {
    if(l == r) return dp[l][r] = 0;
    if(seen[l][r]) return dp[l][r];
    seen[l][r] = 1;
    ll D = stMax.get(l,r)-stMin.get(l,r);
    return dp[l][r] = D + min(solve(l+1,r),solve(l,r-1));
}



int main () {
    cin>>n;
    a.resize(n);
    memset(seen,0,sizeof seen);
    for(int i = 0; i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    stMin.build(a);
    stMax.build(a);

    cout<<solve(0,n-1)<<"\n";

}