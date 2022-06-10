#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        string a,b,c = "";
        cin>>a>>b;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll ptrA = 0, ptrB = 0, cntA = 0, cntB = 0;
        while(ptrA<n && ptrB<m){
            if(cntA < k && a[ptrA]<b[ptrB]) {
                c+=a[ptrA];
                ptrA++;
                cntA++;
                cntB = 0;
            }
            else if(cntA < k  && cntB == k){
                c+=a[ptrA];
                ptrA++;   
                cntA++;
                cntB = 0;
            }
            else {
                c+=b[ptrB];
                ptrB++;
                cntB++;
                cntA = 0;
            }
        }
        cout<<c<<"\n";
    }
}