#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    ll t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<ll> isPro(n+1);
        vector<ll> numTasks(n+1);
        for(int i = 0; i<m; i++){
            ll b;
            cin>>b;
            numTasks[b]++;
            isPro[b] = 1;
        }
        ll res = 0;
        ll done = 0, tot = m;
        priority_queue<tuple<ll,ll,ll>> pq;
        for(int i = 1; i<=n; i++) {
            if(isPro[i]) pq.push({0,1,i});
            else pq.push({0,0,i});
        }
        while(tot-done > 0) {
            auto [tt, pro, cur] = pq.top();
            pq.pop();
            if(!isPro[cur]) {
                done++;
                pq.push({tt-2,0,cur});
                res = tt-2;

            }
            else {
                numTasks[cur]--;
                tot--;
                if(numTasks[cur] > 0) pq.push({tt-1,1,cur});
                else {
                    isPro[cur] = 0;
                    pq.push({tt-1,0,cur});
                }
                res = tt-1;
            }
        }
        cout<<-res<<"\n";
    }
}