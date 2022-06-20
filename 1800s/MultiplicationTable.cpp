#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m,k;

ll count(ll a){
    ll count = 0;
    for(int i = 1; i<=n; i++){
        ll b = a/i;
        count+= min(b,m);
    }
    return count;
}

int main() {
    cin>>n>>m>>k;

    ll a = 1, b = n*m;
    if(n == m && n == 1) {
        cout<<"1\n";
        return 0;
    }
    while(a<=b){
        ll c = a+(b-a)/2;
        ll ct = count(c), ct2 = count(c-1);
        if(ct >= k && ct2 < k){
            cout<<c<<"\n";
            break;
        }
        else if(ct < k){
            a = c+1;
        }
        else {
            b = c-1;
        }
    }
}