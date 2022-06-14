#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main() {
    ll q,n;
    cin>>q;
    while(q--){
        cin>>n;
        vector<ll> a(2*n),col(n);
        ll start = -1;
        for(int i = 0; i<n; i++) {
            cin>>a[i];
            a[i+n] = a[i];
            if(i>0 && start == -1 && a[i] != a[i-1]){
                start = i;
            }
        }
        if(start == -1){
            cout<<"1\n";
            for(int i = 0; i<n; i++) cout<<"1 ";
            cout<<"\n";
        }
        else{
            ll color = 1, m = 2;
            ll twoEquals = -1;
            for(int i = 0; i<n; i++){
                col[i] = color;
                color = color == 1? 2 : 1;
                if(twoEquals == -1 && i>0 && a[i] == a[i-1]) twoEquals = i;
                else if(twoEquals == -1 && i == 0 && a[i] == a[n-1]) twoEquals = 0;
            }
            if(n%2 != 0) {
                if(twoEquals != -1){
                    if(twoEquals == 0) {
                        col[n-1] = 1;
                    }
                    else{
                        col[twoEquals] = col[twoEquals-1];
                        color = col[twoEquals] == 1? 2 : 1;
                        for(int i = twoEquals+1; i<n; i++){
                            col[i] = color;
                            color = color == 1? 2 : 1;
                        }
                    }
                }
                else {
                    col[n-1] = 3;
                    m = 3;
                }
            }
            cout<<m<<"\n";
            for(int i = 0; i<n; i++) cout<<col[i]<<" ";
            cout<<"\n";

        }
    }
}