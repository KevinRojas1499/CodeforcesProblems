#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<ll> a(n);
        bool allZero = true;
        ll numberOfNonZeroSegments = 0;
        for(int i = 0; i<n; i++) {
            cin>>a[i];
            if(a[i] != 0) allZero = false;
        }
        bool interval = false;
        for(int i = 0; i<n; i++) {
            if(a[i] == 0 && !interval){
                continue;
            }
            else if(a[i] == 0 && interval){
                interval = false;
            }
            else if(interval) {
                continue;
            }
            else{
                interval = true;
                numberOfNonZeroSegments++;
            }
        }
        if(allZero){
            cout<<"0\n";
        }
        else if(numberOfNonZeroSegments == 1){
            cout<<"1\n";
        }
        else{
            cout<<"2\n";
        }

    }
}