#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> a(n),count(n+1,0),b(n);
        for(int i = 0;i<n; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }

        ll ptrA = 0;
        bool possible = true;
        vector<ll> newA;
        for(int i = 0; i<n; i++){
            if(a[ptrA] == b[i]){
                newA.push_back(a[ptrA]);
                ptrA++;
            }
            else {
                for(; ptrA<=n; ptrA++){
                    if(ptrA> 0 && a[ptrA-1] == b[i] && count[a[ptrA-1]]){
                        newA.push_back(a[ptrA-1]);
                        count[a[ptrA-1]]--;
                        break;
                    }
                    if(ptrA < n && a[ptrA] != b[i]){
                        count[a[ptrA]]++;
                    }
                    else if(ptrA< n && a[ptrA] == b[i]) {
                        newA.push_back(b[i]);
                        ptrA++;
                        break;
                    }
                }
            }
        }

        if(newA.size() == n){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}