#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n == m && m ==1 ) cout<<"0\n";
        else cout<<min(n+2*(m-1),m+2*(n-1))<<"\n";
    }
}