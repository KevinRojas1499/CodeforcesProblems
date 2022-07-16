#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 105;

map<pair<vector<ll>,ll>,char> dp;
map<pair<vector<ll>,ll>,bool> seen;

ll t,n;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        vector<ll> a(n);
        ll sum = 0;
        for(int i = 0; i<n; i++) {
            cin>>a[i];
            sum+=a[i];
        }
        bool big = false;
        for(auto aa : a) if(aa > sum/2) big = true;
        if(big) cout<<"T\n";
        else if(sum%2 == 0) cout<<"HL\n";
        else cout<<"T\n";
    }
}