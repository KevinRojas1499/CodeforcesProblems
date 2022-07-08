#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
    ll a,b,c,d,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(a == b && b == c && b == d && a == 1){
            cout<<"2\n";
        }
        else if(a == b && b == c && b == d && a == 0){
            cout<<"0\n";
        }
        else {
            cout<<"1\n";
        }
    }
}