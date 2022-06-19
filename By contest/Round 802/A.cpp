#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll p1 = m*(m+1)/2;
        p1+=m*(n*(n+1)/2 - 1);
        ll p2 = (n-1)*m*m;
        p2+=(m*(m+1))/2;
        p2+= m*(n*(n-1)/2-(n-1));
        p2+=(n-1);
        cout<<min(p1,p2)<<"\n"; 
    }    
}