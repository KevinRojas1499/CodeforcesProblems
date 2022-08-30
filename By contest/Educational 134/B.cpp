#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll t,n,m,sx,sy,d;

ll dist(ll a, ll b){
    return abs(sy-a)+abs(sx-b);
}


int main() {
    cin>>t;
    while(t--){
        cin>>n>>m>>sx>>sy>>d;
        if((dist(sy,1) <= d && dist(sy,n) <=d) || (dist(1,sx)<=d && dist(m,sx)<=d)
        || (dist(1,sx) <= d && dist(sy,1) <= d) || (dist(sy,n) <= d && dist(m,sx) <= d) ||
        (dist(m,n)<=d)){
            cout<<"-1\n";
        }
        else {
            cout<<n+m-2<<"\n";;
        }
    }
}