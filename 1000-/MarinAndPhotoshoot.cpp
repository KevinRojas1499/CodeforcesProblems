#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        ll res = 0;
        vector<ll> boys;
        for(int i = 0; i<n; i++){
            if(s[i] == '0') boys.push_back(i);
        }
        for(int i = 1; i<(ll) boys.size(); i++){
            ll dist = boys[i]-boys[i-1];
            if(dist == 2) res++;
            else if (dist == 1) res+=2;  
        }
        cout<<res<<"\n";
    }
}