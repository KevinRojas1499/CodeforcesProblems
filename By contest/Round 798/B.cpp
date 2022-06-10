#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> p(n);
        vector<ll> newP(n);
        set<ll> nums;
        for(int i = 1; i<=n; i++){
            cin>>p[i-1];
            nums.insert(i);
        }
        if( n == 1){
            cout<<"-1\n";
            continue;
        }
        for(int i = 0; i<n-2; i++){
            for(auto c : nums) {
                if(c == p[i]) continue;
                newP[i] = c;
                nums.erase(c);
                break;
            }
        }   
        ll a = *nums.begin();
        nums.erase(a);
        ll b = *nums.begin();
        if(a == p[n-2] && b == p[n-1]){
            newP[n-2] = b;
            newP[n-1] = a;
        }
        else if(b == p[n-1]){
            newP[n-2] = b;
            newP[n-1] = a;
        }
        else if(a == p[n-2]){
            newP[n-2] = b;
            newP[n-1] = a;
        }
        else{
            newP[n-2] = a;
            newP[n-1] = b;   
        }
        for(int i = 0; i<n; i++){
            cout<<newP[i]<<" ";
        }
        cout<<"\n";
    }
}