#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main (){
    ll n,k;
    cin>>n>>k;
    ll half = (n+1)/2;
    if(k<=half){
        cout<<2*k-1<<"\n";
    }
    else{
        cout<<2*(k-half)<<"\n";
    }
}