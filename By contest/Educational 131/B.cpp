#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    ll t,n,d;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<ll> a;
        set<ll> nums;
        for(int i = 2; i<=n; i++) nums.insert(i);
        a.push_back(1);
        while(nums.size()) {
            ll cur = a.back();
            if(nums.find(cur*2) != nums.end()) {
                a.push_back(cur*2);
                nums.erase(cur*2);
            }
            else {
                a.push_back(*nums.begin());
                nums.erase(nums.begin());
            }
        }
        cout<<"2\n";
        for(auto aa : a) cout<<aa<<" ";
        cout<<"\n";
    }
}