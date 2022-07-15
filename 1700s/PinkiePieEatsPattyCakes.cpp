#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t, n;
vector<ll> aa;

bool possible(ll d) {
    set<pair<ll,ll>, greater<pair<ll,ll>>> canUse;
    vector<ll> count(n+1), sol(n+1);
    for(int i = 1; i<=n; i++) {
        count[i] = aa[i];
        if(aa[i] > 0) canUse.insert({aa[i],i});
    }
    for(int i = 1; i<=n; i++) {
        if(canUse.size() == 0) return false;
        auto [cant, cur] = *canUse.begin();
        canUse.erase(canUse.begin());
        sol[i] = cur;
        count[cur]--;
        if(i-d>= 1 && count[sol[i-d]] > 0) 
            canUse.insert({count[sol[i-d]],sol[i-d]});
    }
    return true;
}

int main (){
    cin>>t;
    while(t--){
        cin>>n;
        aa.assign(n+1,0);
        for(int i = 0; i<n; i++) {
            ll b;
            cin>>b;
            aa[b]++;
        }
        ll a = 0, b = n;
        ll ans = 0;
        while(a<=b) {
            ll c = a+(b-a)/2;
            if(possible(c)) {
                ans = c;
                a = c+1;
            }
            else {
                b = c-1;
            }
        }
        cout<<ans<<"\n";

    }
}