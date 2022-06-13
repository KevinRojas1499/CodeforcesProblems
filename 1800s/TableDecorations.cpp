#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    vector<ll> a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.rbegin(),a.rend());
    if(a[0]>= 2*(a[1]+a[2])) cout<<(a[1]+a[2])<<"\n";
    else cout<<(a[0]+a[1]+a[2])/3<<"\n";
}