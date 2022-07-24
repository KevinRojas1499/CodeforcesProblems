#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct DisjointSet {
	vector<ll> parent, size;

    DisjointSet(ll n) : parent(n+1), size(n+1) {
        for(int i = 1; i<=n ;i++ ) make_set(i);
    }
	
	void make_set(int v) {
	    parent[v] = v;
	    size[v] = 1;
	}
	void union_sets(int a, int b) {
	    a = find_set(a);
	    b = find_set(b);
	    if (a != b) {
		if (size[a] < size[b])
		    swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	    }
	}
	int find_set(int v) {
	    if (v == parent[v])
		return v;
	    return parent[v] = find_set(parent[v]);
	}
};

struct SegmentTree {
        vector<ll> st;
        ll n;
        SegmentTree() {};
        SegmentTree(vector<ll> a) {
            n = a.size();
            st.assign(n*4,0);
            build(a,1,0,n-1);
        }
        void build(vector<ll> &a, ll v, ll tl, ll tr) {
            if(tl == tr) {
                st[v] = a[tl];
            }
            else {
                ll tm = tl+(tr-tl)/2;
                build(a,2*v,tl,tm);
                build(a,2*v+1,tm+1,tr);
                st[v] = max(st[2*v],st[2*v+1]);
            }
        }
        ll query(ll v, ll tl, ll tr, ll l, ll r){
            if(l > r) return -1;
            if(tl == l && tr == r) return st[v];
            ll tm = tl + (tr-tl)/2;
            return max(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr, max(l,tm+1),r));
        }
        ll query(ll l, ll r){
            return query(1,0,n-1,l,r);
        }

        void update(ll v, ll tl, ll tr, ll pos, ll val){
            if(tl == tr) {
                st[v] = val;
            }
            else {
                ll tm = tl+(tr-tl)/2;
                if(pos<= tm) update(2*v,tl,tm,pos,val);
                else update(2*v+1,tm+1,tr,pos,val);
                st[v] = max(st[2*v],st[2*v+1]);
            }
        }
};

vector<vector<pair<ll,ll>>> adj;

struct Data {
    ll lca, maxEdge;
};

struct LCA {
	int n, l;
	int timer;
	vector<int> tin, tout;
	vector<vector<Data>> up;
    LCA() {
        n = adj.size();
        preprocess(1);
    }
	void preprocess(int root) {
	    tin.resize(n);
	    tout.resize(n);
	    timer = 0;
	    l = ceil(log2(n));
	    up.assign(n, vector<Data>(l + 1));
	    dfs(root, root, 0);
	}
	void dfs(int v, int p, int w){
	    tin[v] = ++timer;
	    up[v][0] = {p,w};
	    for (int i = 1; i <= l; ++i){
            auto [lca, maxEdge] = up[v][i-1];
		    auto [lca2, maxEdge2]= up[lca][i-1];
            up[v][i] = {lca2, max(maxEdge,maxEdge2)};
        }
	    for (auto [u,w] : adj[v]) {
            if (u != p) {
                dfs(u, v, w);
            }
        }
	    tout[v] = ++timer;
	}
	bool is_ancestor(int u, int v){
	    return tin[u] <= tin[v] && tout[u] >= tout[v];
	}
	ll lca(int u, int v){
	    if (is_ancestor(u, v))
		return u;
	    if (is_ancestor(v, u))
		return v;
	    for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i].lca, v))
                u = up[u][i].lca;
        }
	    return up[u][0].lca;
	}

    ll maxEdge(int u, int lca) {
        ll res = 0;
        for (int i = l; i >= 0; --i) {
            if (is_ancestor(lca, up[u][i].lca)){
                res = max(res,up[u][i].maxEdge);
                u = up[u][i].lca;
            }
        }
        return res;
    }
};

int main () {
    ll t,n,m,q;
    cin>>t;
    while(t--) {
        cin>>n>>m>>q;
        DisjointSet ds(n+1);
        adj.clear();
        adj.resize(n+1);
        for(int i = 1; i<=m; i++) {
            ll a,b;
            cin>>a>>b;
            if(ds.find_set(a) == ds.find_set(b)) continue;
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
            ds.union_sets(a,b);
        }
        LCA lca;
        vector<ll> connections(n+1);
        for(int i = 2; i<=n ;i++) {
            ll lcaCur = lca.lca(i-1,i);
            connections[i] = max(lca.maxEdge(i-1,lcaCur),lca.maxEdge(i,lcaCur));
        }
        SegmentTree st(connections);
        for(int i = 1; i<=q; i++) {
            ll l,r;
            cin>>l>>r;
            if(l == r) cout<<"0 ";
            else cout<<st.query(l+1,r)<<" ";
        }
        cout<<"\n";
    }
}